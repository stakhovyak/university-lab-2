#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>

using std::vector;

class Polynomial
{
protected:
  std::vector<int> coefficients;
  std::vector<int> degrees;
  
public:
  friend class PolynomList;

  // Constructors
  Polynomial() = default;
  Polynomial (vector<int> &&coeff, vector<int> &&deg);
  Polynomial(const Polynomial &src);	// copy constructor

  // Destructor
  ~Polynomial();
  
  // Functions
  void print() const;

  Polynomial operator + (const Polynomial &rhs) const;

  Polynomial operator - (const Polynomial &rhs) const;

  Polynomial operator * (const Polynomial &rhs) const;

  Polynomial &operator ++ ();	// pre-increment operator

  Polynomial &operator -- ();	// pre-decrement operator
};    

#endif // polynom class
