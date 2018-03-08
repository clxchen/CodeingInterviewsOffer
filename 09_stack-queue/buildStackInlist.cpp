#include "cstack.h"
#include <iostream>





using namespace std;

int main()
{
	CStack<int> ss =	CStack<int>();
	
	try
	{
	
		for(int i = 0; i < 20 ;i++)
		{
			ss.myPush(i);
		}
		auto num = ss.size();
		for(int i = 0; i < num ;i++)
		{
			cout<< "refer:"<<i <<endl;
			cout<< ss.myPop() << endl;
		}
		
	}
	catch(exception)
	{
		 cout << "error" << endl;
	}
	
}
