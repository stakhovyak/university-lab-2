#include <iostream>
#include <vector>
#include "include/polynom.h"

Polynomial::~Polynomial()
{};    

Polynomial::Polynomial (vector<int> &&coeff, vector<int> &&deg)
    : coefficients { move(coeff) }
    , degrees { move(deg) }
  {
    if (coeff.size() != deg.size())
      throw std::invalid_argument("The parameters must be equal size!");
  }

void Polynomial::print() const
{
  for (int i = 0; i < coefficients.size(); ++i)
    {
      if (coefficients[i] != 0)
	{
	  std::cout << coefficients[i] << "x^" << degrees[i];
	  
	  if (i != coefficients.size() - 1)
	    std::cout << " + ";
	}
    }
  std::cout << std::endl;
}

