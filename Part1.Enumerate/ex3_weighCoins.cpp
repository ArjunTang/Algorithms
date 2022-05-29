//POJ1013

#include<iostream>
#include<cstring>
using namespace std;

char le[3][7],ri[3][7],ans[3][7];

bool isFake(char c,bool light){
    char *ple,*pri;
    for(int i=0;i<3;i++){
        if(light){
            ple=le[i];
            pri=ri[i];
        }else{
            ple=ri[i];
            pri=le[i];
        }
        switch (ans[i][0])
        {
        case 'u':
            if(strchr(pri,c) == NULL)
                return false;
            break;
        case 'd':
            if(strchr(ple,c) == NULL)
                return false;
            break;
        case 'e':
            if(strchr(ple,c) == NULL || strchr(pri,c) == NULL)
                return false;
            break;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        for(int i=0;i<3;i++){
            cin>>le[i]>>ri[i]>>ans[i];
        }
        for(char c='A';c<='L';c++){
            if(isFake(c,true)){
                cout<<c<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            else if(isFake(c,false)){
                cout<<c<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
        }
    }
    return 0;
}