#include "aliascheck.h"
#include <deque>

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

  deque<A> adeque;
  A a;
  adeque.push_back(a);
  
  deque<A>::iterator it = adeque.end();
  const A *aptr = &*it;

  aptr->f(ptr);

  return 0; 
}
