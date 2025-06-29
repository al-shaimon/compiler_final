#include <stdio.h>

int main()
{
  int x, y, z;
  float result;
  char status;

  // Using some variables
  x = 10;
  y = 20;
  result = x + y;

  // Multiple uses of same variable
  result = result * 2.5;
  result = result / 3.0;

  printf("Result: %.2f\n", result);

  // Variable z and status are declared but never used
  // This should trigger unused variable warnings

  return 0;
}
