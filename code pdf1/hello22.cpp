#include<iostream>

using namespace std;

int main()
{
	
	int N;
	cin>>N;
	int A=N,B=N;
	cout<<"for loop: "<<endl;
	for(;N-- > 0;)
	{
		cout<<"Hello, World!\n";
	}

	cout<<endl<<"while loop: "<<endl;
	
	while(A-- > 0)
        {
                cout<<"Hello, World!\n";
        }

	cout<<endl<<"do..while  loop: "<<endl;
	do
	{
                cout<<"Hello, World!\n";	
	}
	while(--B>0);
	

	return 0;
}
