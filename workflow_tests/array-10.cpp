#include "aliascheck.h"
#include <array>

using namespace std;

int global_obj;
int *global_ptr = &global_obj;

class A {
  public:
    virtual void f(int *i) const {
      MUSTALIAS(global_ptr, i);
    }
};

int main(int argc, char **argv)
{
  int *ptr = &global_obj;

  array<const A *, 2> aarray;
  A *a1 = new A;

  aarray.fill(a1);

  const A *aptr = aarray[0];

  aptr->f(ptr);

  return 0; 
}
