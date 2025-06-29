#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_VARIABLES 100
#define MAX_NAME_LEN 50

typedef struct
{
  char name[MAX_NAME_LEN];
  int declared;
  int used;
} Variable;

extern Variable symbolTable[MAX_VARIABLES];
extern int varCount;

// Function declarations
int findVar(char *name);
void declareVar(char *name);
void useVar(char *name);
void printSymbolTableSummary(void);

#endif
