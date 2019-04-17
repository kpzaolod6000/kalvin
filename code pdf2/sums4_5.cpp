#include<iostream>

using namespace std;

int sum(const int numbers[],const int numbersLen)
{
	int sum=0;
	for(int i=0;i<numbersLen;++i)
	{
		sum += numbers[i];
	}
	return sum;
}

int main()
{
	int p[]={10,20,30,40},q=4;
	cout<<sum(p,q);
}
