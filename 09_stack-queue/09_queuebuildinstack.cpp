#include "cqueue.h"

template<typename T> void CQueue<T> :: appendTail( const T& element)
{
	stack1.push(element);
}

template<typename T> void CQueue<T> :: deleteHead( )
{
	if(stack2.size() <= 0)
	{
		while(stack1.size()>0)
		{
			T &data = stack1.top();
			stack2.push(data);
			stack1.pop();
		}
	}
	
	if(stack2.size() == 0)
		throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();
	
	return head;
}

