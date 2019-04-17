#include<iostream>

using namespace std;

void tranpose(const int input[][2],int output[][3])
{
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<2;++j)
		{
			output[j][i] = input[i][j];	
		}
	}
}

int main()
{
	int m[][2]={{1,2},{3,4},{5,6}};
	int n[][3]={};
	tranpose(m,n);
	
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<3;++j)
		{
			cout<<n[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
