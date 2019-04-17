#include<iostream>

using namespace std;

void swap(int **x,int **y)
{
	int *tmp = *x;
	*x=*y;
	*y=tmp;
}

int main()
{
	int x=5,y=6;
	int *ptr1=&x,*ptr2=&y;
	swap(&ptr1,&ptr2);
	cout<<*ptr1<<' '<<*ptr2;
}
