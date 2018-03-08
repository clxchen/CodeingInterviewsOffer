
#include "cstack.h"
#include <list>

using namespace std;

template< typename T> void CStack::myPush( const T& t)
{
  if(list1.size() != 0)
      list1.push_back(t);
  else if(list2.size() != 0)
      list2.push_back(t);
  else
      throw new exception("stack out of order");
}

template< typename T>  T CStack::myPop(void)
{
   T temp;
  if(list1.size() != 0)
  {
    while(list1.size() > 1)
    {
        list2.push_back(list1.pop_front()); 
    }
    temp =  list1.pop_front();
  }
  else if(list2.size() != 0)
  {
    while(list2.size() > 1)
    {
        list1.push_back(list2.pop_front()); 
    }
    temp = return list2.pop_front();  
  }
  else
   throw new exception("stack is empty");
   
   return temp;
}
