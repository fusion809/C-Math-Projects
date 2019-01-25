// Function to calculate the absolute value of a number
#include <stdio.h>
#include <cubeqroot.h>

int main (void)
{
  float a, b, c, d, x, epsilon;
  printf ("Enter five numbers \nFirst four are a, b, c, d in ax^3 + bx^2 + cx + d = 0. Fifth is the absolute error tolerance (epsilon) to be applied. Separate all input numbers with commas): \n");
  scanf ("%f, %f, %f, %f, %f", &a, &b, &c, &d, &epsilon);
  x = cubeqRoot(a,b,c,d,epsilon);
  printf ("cubeqRoot(a,b,c,d)   = %.15f", x);
  return 0;
}
