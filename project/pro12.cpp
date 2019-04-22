#include<iostream>

using namespace std;

int main()
{
    for(long long k=10000;k<=10000000;++k)
    {
    long long b,acc=0;
    long long verdd=k*(k+1)/2;
    long long cont=k*(k+1)/2;
    long long expo,result=1;
    for(int i=2;cont>1;i++)
    {
        while(cont%i==0)
        {
            b=cont/i;
            cont=b;
            acc++;    
        }
        expo=acc+1;
        result*=expo;
        acc=0;
    }
    cout<<"el numero: "<<verdd<<" tiene: "<<result<<endl;
    if(result>=500)
    {
        cout<<"el primer numero es: "<<verdd<<" tiene: "<<result<<" divisores"<<endl;
        break;
    }
    }
    return 0;
}
