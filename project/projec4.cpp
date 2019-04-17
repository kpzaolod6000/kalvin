nclude <iostream>
#include <string>
#include <sstream>

using namespace std;

string IntToString (int a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}
int IntToString(string x){
        for(int i=0;i<x.length()/2+1;i++){
                if(x[i]!=x[x.length()-i-1])return 0;
        }
        return 1;
}

int palin(string x){
        for(int i=0;i<x.length()/2;i++){
                if(x[i]!=x[x.length()-i-1])return 0;
        }
return 1;
}

int main(){

        int largest=0,x;
        for(int i=100;i<=999;i++){
                for(int j=100;j<=999;j++){
                        int x=i*j;
                        if(palin(IntToString(x))){
                                if(x>largest){
                                        largest=x;
                                }
                        }
                }
        }
        cout<<largest<<endl;
        return 0;
}
