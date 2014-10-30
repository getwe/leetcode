/***************************************************************************
 * 
 * @file main_dp.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/10/30
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/wildcard-matching/
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */

#include<iostream>
#include<vector>
#include<strings.h>

using namespace std;

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {

            int row = strlen(s) + 1;
            int col = strlen(p) + 1;

            vector<int> lastLine(col,0);
            vector<int> currLine(col,0);

            lastLine[0] = 1;
            for (int j=1;j<col;j++){
               if (p[j-1] == '*'){
                    lastLine[j] = lastLine[j-1];
                } else{
                    lastLine[j] = 0;
                }
            }

            for (int i=1;i<row;i++){
                currLine[0] = 0;
                for (int j=1;j<col;j++){
                    if (p[j-1] == '*'){
                        currLine[j] = currLine[j-1] || lastLine[j];
                    } else if (p[j-1] == '?'){
                        currLine[j] = lastLine[j-1];
                    } else if (s[i-1] == p[j-1]){
                        currLine[j] = lastLine[j-1];
                    } else {
                        currLine[j] = 0;
                    }
                }
                // ! Optimization !
                bool equal = true;
                for (int j=0;j<col;j++){
                    if (lastLine[j] != currLine[j]){
                        equal = false;
                        break;
                    }
                }
                if (equal){
                    //return lastLine[col-1];
                }
                // ! Optimization !
                currLine.swap(lastLine);
            }
            return lastLine[col-1];
        }
};

int main() {

    Solution s;
    cout<<s.isMatch("","*")<<"\ttrue"<<endl;
    cout<<s.isMatch("","*a*")<<"\tfalse"<<endl;
    cout<<s.isMatch("aa","a")<<"\tfalse"<<endl;
    cout<<s.isMatch("aa","aa")<<"\ttrue"<<endl;;
    cout<<s.isMatch("aaa","aa")<<"\tfalse"<<endl;
    cout<<s.isMatch("aa", "*")<<"\ttrue"<<endl;
    cout<<s.isMatch("aa", "a*")<<"\ttrue"<<endl;
    cout<<s.isMatch("ab", "?*")<<"\ttrue"<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<"\tfalse"<<endl;
    cout<<s.isMatch("aaaaaa","*aaaaa*")<<"\ttrue"<<endl;
    cout<<s.isMatch("cabab","*ab")<<"\ttrue"<<endl;

    // 时间上一直跑不过的case,最坏情况o(m^n)
    // 这题不能用动态规划来解
    // "aa...(N个a)...aa", "*aa...(N个a)...aa*"
}
















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
