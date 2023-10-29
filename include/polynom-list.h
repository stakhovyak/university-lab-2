#ifndef POLYNOM_LIST_H
#define POLYNOM_LIST_H

#include <vector>
#include "polynom.h"

using std::vector;

class PolynomList
{
protected:
  vector<Polynomial> polynomials;
  
public:
  friend Polynomial sumAll (const PolynomList &pl);
 
  // Constructors
  PolynomList();

  // Destructors
  ~PolynomList();

  PolynomList &operator += (const Polynomial &pol);

  PolynomList &operator ++ ();	// pre increment operator

  PolynomList &operator -- ();	// pre decrement operator

  // Function to show all members of the list
  void showAll() const;
};

#endif // polynom list
