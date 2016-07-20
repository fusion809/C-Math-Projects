// Function to calculate the absolute value of a number
#include <stdio.h>
float absoluteValue (float x)
{
  if ( x < 0 )
  x = -x;
  return (x);
}

// Function to compute the cubic root of a number
float cubicRoot (float x)
{
  const float epsilon = .0000001;
  float guess = 1.0;
  while ( absoluteValue (guess * guess * guess - x) >= epsilon )
  guess = ( x/(guess * guess) + 2*guess ) / 3.0;
  return guess;
}

int main (void)
{
  printf ("cubicRoot (2.0)   = %.15f\n", cubicRoot (2.0));
  return 0;
}
