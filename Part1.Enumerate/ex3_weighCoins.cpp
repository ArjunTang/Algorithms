#include<iostream>
#include<string>
using namespace std;

int n;
char le[3][7], ri[3][7], ans[3][7];
char *ple,*pri;

bool isFake(char c,bool light);

int main(){
    cin >> n;
    for(int i=n;i>0;i--){
        for(int j=0;j<3;j++){
            cin >> le[j] >> ri[j] >> ans[j];
        }
        for(char j='A';j<='L';j++){
            if(isFake(j,true)){
                cout<<j<<" is fake and it is light"<<endl;
            }
            else if(isFake(j,false)){
                cout<<j<<" is fake and it is dark"<<endl;
            }
        }
    }

    return 0;
}

bool isFake(char c,bool light){
    for(int i=0;i<3;i++){
        if(light){
            ple=le[i];
            pri=ri[i];
        }
        else{
            ple=ri[i];
            pri=le[i];
        }
        switch (ans[i][0])
        {
        case 'e':
            if(strchr(ple,c) || strchr(pri,c))
                return false;
            break;
        case 'u':
            if(strchr(pri,c) == NULL)
                return false;
            break;
        case 'd':
            if(strchr(ple,c) == NULL)
                return false;
            break;
        }
    }
    return true;
}