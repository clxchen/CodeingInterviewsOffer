//for finding the duplicate number

bool duplicate(int numbers[],int length, int* duplication)
{
    if(numbers == nullptr || length <=0)
      return false;
    for(int i = 0; i < length;++i)
    {
      if(numbers[i] < 0 || numbers[i] >length - 1)
        return false;
    }
  for(int i = 0; i< length ; ++i)
  {
    while(numbers[i] != i)
    {
      if( numbers[i] = numbers[numbers[i]])
      {
        *duplication = numbers[i];
        return true;
      }
      //交换两数
      int temp = numbers[i];
      numbers[i] = numbers[temp];
      numbers[temp] = temp;
    }
  }
}

#include <iostream>
using namespace std;
//测试用例
void test1(void)
{
    int vec[10] = {1,2,2,3,4,5,6,7,8,9};
    int res;
    auto f = duplicate(vec,10,&res);
    if(false == f)
        cout << "no duplication or input error" <<endl;
    else
        cout << "duplication number: " << res << endl;
    
}

void test2(void)
{
    int vec[10] = {1,2,0,3,4,5,6,7,8,9};
    int res;
    auto f = duplicate(vec,10,&res);
    if(false == f)
        cout << "no duplication or input error" <<endl;
    else
        cout << "duplication number: " << res << endl;
    
}

void test3(void)
{
    int vec[10] = {1,2,11,3,4,5,6,7,8,9};
    int res;
    auto f = duplicate(vec,10,&res);
    if(false == f)
        cout << "no duplication or input error" <<endl;
    else
        cout << "duplication number: " << res << endl;
    
}

int main()
{
    test1();
    test2();
    test3();
}
