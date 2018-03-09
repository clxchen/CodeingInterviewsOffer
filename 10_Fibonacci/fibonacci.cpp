long long fibonacci(unsigned n)
{
    int result[2] = {0,1};
    if(n<2)
        return result[i];
        
     long long number1 = 1;
     long long number2 = 0;
     for(int i = 2 ; i < n; ++i)
     {
        fN = number1 +  number2;
        number2 = number1;
        number1 = fN
     }
     
     return fN;
}

//一只青蛙一次可以跳上一级台阶，也可以跳上二级台阶，求青蛙跳上n级台阶有多少种算法。

long long flogJump1(unsigned n)
{
    int result[3] = {0,1,2};
    if(n<3)
        return result[i];
        
     long long number1 = 2;
     long long number2 = 1;
     for(int i = 3 ; i < n; ++i)
     {
        fN = number1 +  number2;
        number2 = number1;
        number1 = fN
     }
     
     return fN;
}

