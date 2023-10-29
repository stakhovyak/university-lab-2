#include <iostream>
#include "include/polynom.h"
#include "include/polynom-list.h"

Polynomial sumAll (const PolynomList &pl)
{
  Polynomial result;

  for (const auto &pol : pl.polynomials)
    {
      result = result + pol;
    }

  return result;
}

int main ()
{
  {
     Polynomial p1 ({10,2,4,6}, {3,2,1,8});
     Polynomial p2 ({2,1,6,10}, {1,6,7,7});

     PolynomList list;
     list += p1;
     list += p2;

     list.showAll();

     std::cout << "-------------------" << std::endl;

     Polynomial p3;
     p3 = p1 + p2;
     p3.print();

     Polynomial p4;
     p4 = p1 - p2;
     p4.print();

     Polynomial p5;
     p5 = p1 * p2;
     p5.print();

     std::cout << "-------------------" << std::endl;

     list += p5;
     list.showAll();

     std::cout << "-------------------" << std::endl;

     ++p1;
     p1.print();

     sumAll(list);
     list.showAll();
  }

  return 0;
}

