#include "include/polynom.h"
#include "include/polynom-list.h"

int main ()
{
  {
     Polynomial p1 ({10,2,4,6}, {3,2,1,8});
     Polynomial p2 ({2,1,6,10}, {3,6,7,7});

     PolynomList list;
     list.addNew(p1);
     list += p2;

     list.showAll();

     p1.print ();
  }

  return 0;
}

