//POJ1222
//基本思路：使用局部枚举的方式

#include <iostream>
#include <memory>
#include <string>
#include <cstring>
using namespace std;

char oriLights[5];
char lights[5];
char result[5];

int getBit(char c,int i){
    return (c>>i)&1;
}
void setBit(char &c,int i,int v){
    c=(c&(~(1<<i)))|(v<<i);
}
void flipBit(char &c,int i){
    c=(c^(1<<i));
}

void outputResult(int t,char result[]){
    cout<<"PUZZLE #"<<t<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<getBit(result[i],j);
            if(j<5)
                cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                int s;
                cin>>s;
                setBit(oriLights[i],j,s);
            }
        }
        for(int n=0;n<64;n++)
        {
            int switchs=n;
            memcpy(lights,oriLights,sizeof(oriLights));
            for(int i=0;i<5;i++){
                result[i]=switchs;
                for(int j=0;j<6;j++){
                    if(getBit(switchs,j)){
                        if(j>0)
                            flipBit(lights[i],j-1);
                        flipBit(lights[i],j);
                        if(j<5)
                            flipBit(lights[i],j+1);
                    }
                }
                if(i<4)
                    lights[i+1]^=switchs;
                switchs=lights[i];
            }
            if(lights[4]==0){
                outputResult(t,result);
                break;
            }
        }
    }
}