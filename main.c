/*
 * C Source Code Analyzer
 * ======================
 * A comprehensive tool for analyzing C source code to detect:
 * - Variable declarations
 * - Variable usage
 * - Unused variables
 * - Undeclared variables
 *
 * This modular version is organized into separate files for better maintainability.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "symbol_table.h"
#include "analyzer.h"
#include "utils.h"

void printWelcomeBanner(void)
{
  printf("===================================================================\n");
  printf("|                    C SOURCE CODE ANALYZER                      |\n");
  printf("|                         Version 2.0                            |\n");
  printf("|                                                                 |\n");
  printf("|  Features:                                                      |\n");
  printf("|  * Variable Declaration Detection                               |\n");
  printf("|  * Variable Usage Analysis                                      |\n");
  printf("|  * Unused Variable Detection                                    |\n");
  printf("|  * Undeclared Variable Detection                                |\n");
  printf("|  * Comment and String Filtering                                 |\n");
  printf("===================================================================\n\n");
}

void printAnalysisResults(void)
{
  int unusedCount = 0, usedCount = 0;

  printf("\n===================================================================\n");
  printf("|                        ANALYSIS RESULTS                        |\n");
  printf("===================================================================\n\n");

  // Count statistics
  for (int i = 0; i < varCount; i++)
  {
    if (symbolTable[i].used)
      usedCount++;
    else
      unusedCount++;
  }

  // Print detailed results
  printf(">> ANALYSIS STATISTICS:\n");
  printf("   * Total variables declared: %d\n", varCount);
  printf("   * Variables used: %d\n", usedCount);
  printf("   * Variables unused: %d\n", unusedCount);
  printf("\n");

  if (unusedCount > 0)
  {
    printf(">> WARNING: UNUSED VARIABLES DETECTED:\n");
    printf("   The following variables were declared but never used:\n");
    for (int i = 0; i < varCount; i++)
    {
      if (!symbolTable[i].used)
      {
        printf("   * '%s' - Consider removing if not needed\n", symbolTable[i].name);
      }
    }
    printf("\n");
  }
  else
  {
    printf(">> GREAT! No unused variables found.\n\n");
  }

  // Print symbol table
  printSymbolTableSummary();

  // Print recommendations
  printf(">> RECOMMENDATIONS:\n");
  if (unusedCount > 0)
  {
    printf("   * Remove unused variables to improve code cleanliness\n");
    printf("   * Check if unused variables indicate incomplete functionality\n");
  }
  if (usedCount == varCount && varCount > 0)
  {
    printf("   * Excellent! All declared variables are being used\n");
  }
  printf("   * Consider adding comments for complex variable usage\n");
  printf("   * Use meaningful variable names for better code readability\n");
}

int main()
{
  char filename[100];

  // Print welcome banner
  printWelcomeBanner();

  // Get filename from user
  printf(">> Enter C source filename to analyze: ");
  scanf("%s", filename);

  // Perform analysis
  analyzeFile(filename);

  // Print results
  printAnalysisResults();

  // Print completion info
  printf("\n===================================================================\n");
  printf("|                     ANALYSIS COMPLETED                         |\n");
  printf("===================================================================\n");
  printf(">> Analysis completed\n");
  printf(">> File analyzed: %s\n", filename);
  printf(">> Thank you for using C Source Code Analyzer!\n\n");

  return 0;
}
