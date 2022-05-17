#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string expression){
    stack<char> s;

    for(int i=0;i<expression.length();i++){
        char ch=expression[i];

        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str="{([({{{{[]}}}})])}";

    if(isValidParenthesis(str)){
        cout<<"The given string is a valid parenthesis."<<endl;
    }
    else{
        cout<<"The given string is not a valid parenthesis."<<endl;
    }

    return 0;
}