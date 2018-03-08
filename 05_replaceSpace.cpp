void ReplaceBlank(char string[],int length)
{
	if(nullptr == string || length <= 0 )
		return;
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		++originalLength;
		if(' ' == string[i])
			++numberOfBlank;
		++i;	
	}	

	
	int newLength = originalLength + numberOfBlank*2;
	if(newLength > length)
		return;
		
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';	
			string[indexOfNew--] = '2';	
			string[indexOfNew--] = '%';	
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];			
		}
		--indexOfOriginal;	
	}
}

// ====================测试代码====================
#include <cstdio>
#include <cstring>
void Test(const char* testName, char str[], int length, const char* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    //char str2[] = "hello%20world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
