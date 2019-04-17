#include<iostream>

using namespace std;
int sum(const int x,const int y){return x+y;}
double sum(const double x,const double y){return x+y;}

int main()
{
	cout<<sum(4,8);
	cout<<sum(4.233554,45.5556);
}
