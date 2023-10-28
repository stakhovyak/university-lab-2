#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include <vector>

using std::vector;

class Polynomial
{
public:
  // Constructors
  Polynomial (vector<int> &&coeff, vector<int> &&deg);

  // Destructor
  ~Polynomial();
  
  // Functions
  void print() const;

private:
  std::vector<int> coefficients;
  std::vector<int> degrees;
};    

#endif // polynom class
