#ifndef POLYNOM_LIST_H
#define POLYNOM_LIST_H

#include <iostream>
#include <vector>
#include "polynom.h"

using std::vector;

class PolynomList
{
private:
  vector<Polynomial> polynomials;
  
public:
  // Constructors
  PolynomList();

  // Destructors
  ~PolynomList();

  // Function to add a polynomial to the list
  void addNew(const Polynomial &pol);
 

  PolynomList &operator += (const Polynomial &pol);

  // Function to show all members of the list
  void showAll() const;
};

#endif // polynom list
