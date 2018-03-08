#ifndef C_STACK_H_
#define C_STACK_H_

#include <list>
#include <exception>

using namespace std;

template<typename T> class CStack
{
  public:
      CStack(void) = default;
      ~CStack(void) = default;
      
      void myPush(const T&);
      T myPop(void);
     // int size() const{return list1.size()+ list2.size();};
      int size() const{return m_size;};
private:
   list<T> list1;
   list<T> list2;
   int m_size;
};

//extern template<typename T> void CStack<T>::myPush( const T&);
//extern template<typename T>  T CStack<T>::myPop(void);	



template< typename T> void CStack<T>::myPush( const T& t)
{  	
  if(list1.size() != 0)
      list1.push_back(t);
  else if(list2.size() != 0)
      list2.push_back(t);
  else
  		list1.push_back(t);
  		
  ++m_size;
}

template< typename T>  T CStack<T>::myPop(void)
{
  T temp;
  if(list1.size() != 0)
  {
    while(list1.size() > 1)
    {
        list2.push_back(*list1.begin());
        list1.pop_front(); 
    }
    temp =  *list1.begin();
    list1.pop_front(); 
  }
  else if(list2.size() != 0)
  {
    while(list2.size() > 1)
    {
        list1.push_back(*list2.begin()); 
        list2.pop_front(); 
    }
    temp = *list2.begin(); 
    list2.pop_front();  
  }
  else
   ;//throw new exception("stack is empty");
   
   --m_size;
 
   return temp;
}


#endif
