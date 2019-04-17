#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	bool g=true;
	for(int j=1;j<=n;j++)
	{
		int tmp=n/j;
		for(int i=2;i<=tmp/2;i++)
		{
			if (tmp%i==0)
			{
				g=false;
				cout<<i<<endl;
			}
		}
		if (g==true)
		{
			cout<<tmp<<endl;
			/*int a[]={},i=0;
			while(true)
			{
				a[i]=tmp;
				i++;
				cout<<a[i]<<" ";
				false;
			}*/
		}
	}

}
