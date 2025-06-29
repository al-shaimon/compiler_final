#include <stdio.h>
#include <string.h>

int main()
{
  // Mixed variable declarations and usage
  int count = 0;
  float average, sum;
  char name[50];
  int numbers[5];

  // Using variables in different contexts
  sum = 0.0;

  for (count = 0; count < 5; count++)
  {
    numbers[count] = count * 10;
    sum += numbers[count];
  }

  average = sum / 5.0;

  // String operations
  strcpy(name, "Test");
  printf("Name: %s\n", name);
  printf("Average: %.2f\n", average);

  // Using undefined variable (should cause error)
  total = sum + 100; // 'total' not declared

  // Redeclaring a variable (should cause warning)
  int count;

  return 0;
}
