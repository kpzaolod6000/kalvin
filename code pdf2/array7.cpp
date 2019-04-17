#include<iostream>

using namespace std;

int stringLength(const char *str)
{
	int length = 0;
	while(*(str+length)!='\0')
	{
		++length;
	}
	return length;
}

int main()
{
	char p[]={"hello world"};
	char *array=p;
	cout<<stringLength(array);
}
