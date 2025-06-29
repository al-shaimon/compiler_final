#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "analyzer.h"
#include "symbol_table.h"
#include "utils.h"

static int lineNumber = 0;

// Tokenize and analyze a line
void analyzeLine(char *line)
{
  lineNumber++;
  printf(">> Processing Line %d: %s", lineNumber, line);

  stripCommentsAndStrings(line);

  // --- Declaration parsing ---
  char lineCopy[256];
  strcpy(lineCopy, line);

  char *token = strtok(lineCopy, " \t\n;");

  if (token && (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0))
  {
    printf(">> Found variable declaration(s) of type '%s'\n", token);
    token = strtok(NULL, ",;\n ");
    while (token != NULL)
    {
      // Skip function definitions like main()
      if (strchr(token, '(') != NULL || strchr(token, ')') != NULL)
      {
        token = strtok(NULL, ",;\n ");
        continue;
      }
      // Skip braces
      if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0)
      {
        token = strtok(NULL, ",;\n ");
        continue;
      }
      // Remove trailing whitespace
      while (strlen(token) > 0 && isspace(token[strlen(token) - 1]))
      {
        token[strlen(token) - 1] = '\0';
      }
      declareVar(token);
      token = strtok(NULL, ",;\n ");
    }
    return;
  }

  // --- Usage detection ---
  char tempLine[256];
  strcpy(tempLine, line);

  token = strtok(tempLine, " \t\n;(),+-=*/<>!&|[]{}");
  while (token != NULL)
  {
    // Skip braces
    if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0)
    {
      token = strtok(NULL, " \t\n;(),+-=*/<>!&|[]{}");
      continue;
    }

    // Remove trailing () for function calls
    int len = strlen(token);
    if (len > 2 && token[len - 2] == '(' && token[len - 1] == ')')
    {
      token[len - 2] = '\0';
    }

    if (isalpha(token[0]) && !isKeyword(token))
    {
      useVar(token);
    }
    token = strtok(NULL, " \t\n;(),+-=*/<>!&|[]{}");
  }
}

// Analyze entire file
void analyzeFile(const char *filename)
{
  FILE *fp;
  char line[256];

  printf("\n>> Starting analysis of file: %s\n", filename);
  printf("=========================================\n");

  fp = fopen(filename, "r");
  if (!fp)
  {
    printf("ERROR: Cannot open file '%s'.\n", filename);
    return;
  }

  lineNumber = 0; // Reset line counter for each file

  while (fgets(line, sizeof(line), fp))
  {
    char *trim = line;
    while (isspace(*trim))
      trim++;
    if (*trim == '\0' || *trim == '#' || *trim == '\n')
    {
      lineNumber++;
      printf(">> Skipping Line %d (empty/preprocessor): %s", lineNumber, line);
      continue;
    }

    analyzeLine(line);
  }

  fclose(fp);
  printf(">> File analysis completed!\n");
}
