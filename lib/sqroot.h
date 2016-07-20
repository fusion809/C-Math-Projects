#include <absolute.h>
// Function to compute the square root of a number
float squareRoot (float x)
{
  const float epsilon = .0000001;
  float guess = 25.0;
  while ( absoluteValue (guess * guess - x) >= epsilon )
  guess = ( x / guess + guess ) / 2.0;
  return guess;
}
