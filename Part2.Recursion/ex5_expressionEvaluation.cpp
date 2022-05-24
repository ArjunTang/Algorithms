//使用递归解决递归形式的问题

#include<iostream>
using namespace std;
int factor_value();
int term_value();
int expression_value();
int main(){
    cout<<expression_value()<<endl;
    return 0;
}

int expression_value(){
    int result=term_value();
    bool more = 1;
    while(more){
        char op=cin.peek();
        if(op=='+'||op=='-'){
            cin.get();
            int nextTerm=term_value();
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
int term_value(){
    int result=factor_value();
    while(1){
        char op=cin.peek();
        if(op=='*'||op=='/'){
            cin.get();
            int nextFactor=factor_value();
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
int factor_value(){
    int result=0;
    char c=cin.peek();
    if(c=='('){
        cin.get();
        result=expression_value();
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