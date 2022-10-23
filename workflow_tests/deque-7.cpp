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
  A b;
  adeque.push_back(a);
  adeque.push_back(b);
  
  deque<A>::const_iterator it = adeque.begin();
  adeque.erase(it);
  deque<A>::const_iterator itt = adeque.begin();
  const A *aptr = &*itt;

  aptr->f(ptr);

  return 0; 
}
