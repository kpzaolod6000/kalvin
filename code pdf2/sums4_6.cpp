#include<iostream>

using namespace std;

int sum(const int numbers[],const int numbersLen) 
{
	return numbersLen==0 ? 0 : numbers[0] + sum(numbers + 1,numbersLen - 1);
}
int main()
{
	int p[]={1,2,3,4,5},q=5;
        cout<<sum(p,q);
}
