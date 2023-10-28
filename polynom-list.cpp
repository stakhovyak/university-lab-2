#include <iostream>
#include <vector>
#include "include/polynom-list.h"

PolynomList::PolynomList(){};

PolynomList::~PolynomList(){};

void PolynomList::addNew(const Polynomial &pol) { polynomials.push_back(pol); };

PolynomList &PolynomList::operator+= (const Polynomial &pol)
{
  polynomials.push_back(pol);
  
  return *this;
};

void PolynomList::showAll() const
{
  for (const auto &pol : polynomials)
    {
      pol.print();
    }
};
