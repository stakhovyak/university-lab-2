#include <iostream>
#include "include/polynom-list.h"
#include "include/polynom.h"

PolynomList::PolynomList(){};

PolynomList::~PolynomList(){};

PolynomList &PolynomList::operator += (const Polynomial &pol)
{
  if (pol.coefficients.empty() || pol.degrees.empty())
    {
      throw std::invalid_argument("Invalid polynomial!");
    }
  
    polynomials.push_back(pol);
  
  return *this;
};

PolynomList &PolynomList::operator ++ ()
{
  for (auto &pol : polynomials)
    {
      if (pol.coefficients.empty() || pol.degrees.empty())
        {
	  throw std::invalid_argument("Invalid polynomial!");
        }
      
      ++pol;
    }
  
  return *this;
}

PolynomList &PolynomList::operator -- ()
{
  for (auto &pol : polynomials)
    {
      if (pol.coefficients.empty() || pol.degrees.empty())
	{
	  throw std::invalid_argument("Invalid polynomial!");
        }
      
      --pol;
    }

  return *this;
}

void PolynomList::showAll() const
{
  for (const auto &pol : polynomials)
    {
      if (pol.coefficients.empty() || pol.degrees.empty())
        {
	  throw std::invalid_argument("Invalid polynomial!");
        }
      
      pol.print();
    }
};

