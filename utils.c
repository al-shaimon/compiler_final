#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

int inMultiLineComment = 0;

// Check if token is a C keyword or type
int isKeyword(char *word)
{
  const char *keywords[] = {
      "int", "float", "char", "return", "if", "else", "while", "for",
      "void", "double", "long", "short", "unsigned", "signed",
      "const", "static", "struct",
      "printf", "scanf", "main", // common functions
      NULL};

  for (int i = 0; keywords[i]; i++)
  {
    if (strcmp(word, keywords[i]) == 0)
      return 1;
  }
  return 0;
}

// Strip comments and strings from a line (multi-line safe)
void stripCommentsAndStrings(char *line)
{
  int i = 0, j = 0;
  int inString = 0;

  while (line[i] != '\0')
  {
    if (!inMultiLineComment && line[i] == '"' && !inString)
    {
      inString = 1;
      i++;
      continue;
    }
    else if (inString && line[i] == '"')
    {
      inString = 0;
      i++;
      continue;
    }

    if (inString)
    {
      i++;
      continue;
    }

    if (!inMultiLineComment && line[i] == '/' && line[i + 1] == '/')
    {
      break; // single-line comment
    }

    if (!inMultiLineComment && line[i] == '/' && line[i + 1] == '*')
    {
      inMultiLineComment = 1;
      i += 2;
      continue;
    }

    if (inMultiLineComment && line[i] == '*' && line[i + 1] == '/')
    {
      inMultiLineComment = 0;
      i += 2;
      continue;
    }

    if (!inMultiLineComment)
    {
      line[j++] = line[i];
    }

    i++;
  }

  line[j] = '\0';
}
