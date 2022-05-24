//使用递归解决递归形式的问题

#include<iostream>
using namespace std;
int factorValue();
int termValue();
int expressionValue();
int main(){
    cout<<expressionValue()<<endl;
    return 0;
}

int expressinoValue(){
    int result=termValue();
    bool more = 1;
    while(more){
        char op=cin.peek();
        if(op=='+'||op=='-'){
            cin.get();
            int nextTerm=termValue();
            if(op=='+'){
                result+=nextTerm;
            }else{
                result-=nextTerm;
            }
        }
        else{
            more=0;
        }
    }
    return result;
}
int termValue(){
    int result=factorValue();
    while(1){
        char op=cin.peek();
        if(op=='*'||op=='/'){
            cin.get();
            int nextFactor=factorValue();
            if(op=='*'){
                result*=nextFactor;
            }else{
                result/=nextFactor;
            }
        }
        else{
            break;
        }
    }
    return result;
}
int factorValue(){
    int result=0;
    char c=cin.peek();
    if(c=='('){
        cin.get();
        result=expressionValue();
        cin.get();
    }
    else{
        while(isdigit(c)){
            result=result*10+c-'0';
            cin.get();
            c=cin.peek();
        }
    }
    return result;
}