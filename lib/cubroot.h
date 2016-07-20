#include <absolute.h>
// Function to compute the cubic root of a number
float cubicRoot (float x)
{
  const float epsilon = .000001;
  float guess = 1.26;
  while ( absoluteValue (guess * guess * guess - x) >= epsilon )
  guess = ( x/(guess * guess) + 2*guess ) / 3.0;
  return guess;
}
