/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/01
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/valid-parentheses/
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
 * input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]"
 * are not.
 */
#include<iostream>
#include<stack>
using namespace std;

class Solution {
    public:
        bool isMatch(char a,char b){
            return ( a == '[' && b == ']') ||
                ( a == '{' && b == '}' ) ||
                ( a == '(' && b == ')' );
        }
        bool isValid(string s) {
            stack<char> Stack;
            for (int i=0;i<s.size();i++){
                if (Stack.empty()){
                    Stack.push(s[i]);
                    continue;
                }
                if (isMatch(Stack.top(),s[i])){
                    Stack.pop();
                } else {
                    Stack.push(s[i]);
                }
            }
            return Stack.empty();
        }
};

int main() {
    Solution s;
    cout<<s.isValid("")<<"\ttrue"<<endl;
    cout<<s.isValid("[]")<<"\ttrue"<<endl;
    cout<<s.isValid("[]()")<<"\ttrue"<<endl;
    cout<<s.isValid("[{}]()")<<"\ttrue"<<endl;
    cout<<s.isValid("[{(}]())")<<"\tfalse"<<endl;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
