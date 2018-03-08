

int countRange(const int *numbers,int length,int start, int end);
int getDuplication(const int *numbers,int length)
{
  if( nullptr == numbers || length <= 0 )
    return -1;
    
  int start = 1;
  int end = length - 1;
  while(end >= start)
  {
      int middle = ((end - start) >> 1) + start;
      int count = countRange(numbers,length,start,middle);
      if(start == end)
      {
          if(count > 1)
            return count;
          else
            break;
      }
      
      if (count > (middle - start + 1))
          end = middle;
      else
          start = middle + 1;
  }
  return -1;
}

int countRange(const int *numbers,int length,int start, int end)
{
    int count = 0;
    if(nullptr == numbers || length <= 0)
        return 0;
    for(int i = 0; i < length; ++i )
    {
        if (numbers[i] >= start && numbers[i] <= end)
          ++count;  
    }
    return count;
}


#include  <iostream>
using namespace std;


void test1()
{
    int a[10] = {1,2,2,4,5,6,7,8,9,9};
    auto res = getDuplication(a,10);
    if(res > 1)
        cout << "test1:find duplication" << endl;
    else
        cout << "test1:no find duplication or input error" <<endl;
}

void test2()
{
    int a[10] = {1,2,3,4,5,6,7,8,9};
    auto res = getDuplication(a,10);
    if(res > 1)
        cout << "test2:find duplication" << endl;
    else
        cout << "test2:no find duplication or input error" <<endl;
}

void test3()
{
    int *a = nullptr;
    auto res = getDuplication(a,10);
    if(res > 1)
        cout << "test3:find duplication" << endl;
    else
        cout << "test3:no find duplication or input error" <<endl;
}

int main()
{
    test1();
    test2();
    test3();
}



