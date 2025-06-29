#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

Variable symbolTable[MAX_VARIABLES];
int varCount = 0;

// Helper: Check if a variable exists
int findVar(char *name)
{
  for (int i = 0; i < varCount; i++)
  {
    if (strcmp(symbolTable[i].name, name) == 0)
      return i;
  }
  return -1;
}

// Helper: Add new variable
void declareVar(char *name)
{
  if (varCount >= MAX_VARIABLES)
  {
    printf("ERROR: Symbol table full. Cannot declare '%s'.\n", name);
    return;
  }

  if (findVar(name) != -1)
  {
    printf("WARNING: Variable '%s' is already declared.\n", name);
    return;
  }

  strcpy(symbolTable[varCount].name, name);
  symbolTable[varCount].declared = 1;
  symbolTable[varCount].used = 0;
  varCount++;
  printf(">> Variable '%s' declared successfully.\n", name);
}

// Helper: Mark variable as used
void useVar(char *name)
{
  int idx = findVar(name);
  if (idx == -1)
  {
    printf("ERROR: Variable '%s' used without declaration.\n", name);
  }
  else
  {
    symbolTable[idx].used = 1;
    printf(">> Variable '%s' marked as used.\n", name);
  }
}

// Print symbol table summary
void printSymbolTableSummary(void)
{
  printf("\n=== SYMBOL TABLE SUMMARY ===\n");
  printf("Total variables found: %d\n", varCount);

  if (varCount > 0)
  {
    printf("\n%-20s %-10s %-10s\n", "Variable Name", "Declared", "Used");
    printf("----------------------------------------\n");
    for (int i = 0; i < varCount; i++)
    {
      printf("%-20s %-10s %-10s\n",
             symbolTable[i].name,
             symbolTable[i].declared ? "Yes" : "No",
             symbolTable[i].used ? "Yes" : "No");
    }
  }
  printf("============================\n\n");
}
