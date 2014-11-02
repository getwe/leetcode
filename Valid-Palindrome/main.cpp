/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/10/30
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/valid-palindrome/
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and
 * ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an
 * interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include<iostream>

using namespace std;

class Solution {
    public:
        bool skip(char a){
            if ( (a >= 'a' && a <= 'z') ||
                 (a >= 'A' && a <= 'Z') ||
                 (a >= '0' && a <= '9') )
            {
                return false;
            }
            return true;
        }
        bool isPalindrome(string s) {
            int i=0;
            int j=s.size()-1;
            while (i <= j){
                if (skip(s[i])){i++;continue;}
                if (skip(s[j])){j--;continue;}

                if (tolower(s[i]) != tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
};

int main(){
    Solution s;
    cout<<s.isPalindrome("")<<endl;
    cout<<s.isPalindrome("abccba")<<endl;
    cout<<s.isPalindrome("abc")<<endl;

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
