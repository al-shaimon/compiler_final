#include <stdio.h>

int main()
{
  int a, b, c, d;
  float x, y;
  char ch;

  // Perfect scenario - all variables used
  a = 5;
  b = 10;
  c = a + b;
  x = 3.14;
  y = x * 2.0;
  ch = 'A';

  printf("a=%d, b=%d, c=%d\n", a, b, c);
  printf("x=%.2f, y=%.2f\n", x, y);
  printf("ch=%c\n", ch);

  // d is declared but never used - should show warning

  return 0;
}
