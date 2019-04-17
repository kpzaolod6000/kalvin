#include<iostream>

using namespace std;

void reverse(int numbers[],const int numbersLen)
{
	for(int i=0;i<numbersLen/2;++i)
	{
		int tmp = numbers[i];
		int indexFromEnd = numbersLen-i-1;
		numbers[i] = numbers[indexFromEnd];
		numbers[indexFromEnd] = tmp;	
	}
	for(int j=0;j<numbersLen;++j)
	{
		cout<<numbers[j]<<" ";
	}
	cout<<endl;
}

int main()
{
	int p[]={1,2,3,4,5,6,7,8,9};
	reverse(p,9);
	return 0;

}





