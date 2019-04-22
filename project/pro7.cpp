#include<iostream>

using namespace std;

int main()
{
    long indice=1;
    long acc=0;

    for(long i=11;indice<=10001-4;i+=2)
    {
        for(int j=1;j<=i/2;++j)
        {
            if(i%j==0)
            {
                acc++;
            }
        }
        if(acc==1)
        {
            indice++;
            cout<<i<<endl;
        }
        acc=0;
        
    }
    return 0;
}