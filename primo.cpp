#include<iostream>

using namespace std;

int main()
{
	long a[]={};
	bool g=true;
	int cont=0;
	for (int i=10;i>=1;--i)
	{
		for(int j=2;j<=i/2;++j)				
		{
			if (i%j==0)
			{
				g=false;
			}
			if (g==true)
			{
				cont=i;
			}
		}
		for(int k=0;k<10;++k)
		{
			a[k]=cont;
		}
		g=true;
	}
	for(int p=0;p<10;++p)
	{
		cout<<a[p]<<" ";
	}
	return 0;
}

