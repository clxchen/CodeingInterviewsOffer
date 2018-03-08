#ifndef C_STACK_H_
#define C_STACK_H_

#include <list>
using namespace std;

template<typename T> class CStack
{
  public:
      CStack(void) = default;
      ~CStack(void) = default;
      
      void myPush(const &T);
      T myPop(void);
private:
   list<T> list1;
   list<T> list2;
};

#endif
