#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,N;
    cin>>N;

    for(int a=2;a<=N;a++){
        for(int b=2;b<=a-1;b++){
            for(int c=b;c<=a-1;c++){
                for(int d=c;d<=a-1;d++){
                    if(a*a*a==b*b*b+c*c*c+d*d*d){
                        cout<<"Cube = "<<a<<",Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
                    }
                }
            }
        }
    }

    return 0;
}
