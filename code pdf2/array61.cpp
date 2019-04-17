#include<iostream>

using namespace std;

void printArray(const int arr[],const int len)
{
	for(int i=0;i<len;++i)
	{
		cout<<arr[i];
		if (i<len-1)
		{
			cout<<", ";
		}
	}


}
int main()
{
	int p[]={4,5,6,3,2,7};
	printArray(p,6);
	return 0;
}
