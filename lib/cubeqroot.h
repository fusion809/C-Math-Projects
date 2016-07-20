#include <absolute.h>
// Function to compute the cubic root of a number
float cubeqRoot (float a, float b, float c, float d)
{
  const float epsilon = .000001;
  float guess = 1.0;
  while ( absoluteValue (a * guess * guess * guess + b * guess * guess + c * guess + d) >= epsilon )
  guess = guess - (a * guess * guess * guess + b * guess * guess + c * guess + d)/(3 * a * guess * guess + 2 * b * guess + c);
  return guess;
}
