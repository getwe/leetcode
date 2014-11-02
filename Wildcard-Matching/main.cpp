/***************************************************************************
 * 
 * @file main.cpp
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

            const char* s1 = s;
            const char* p1 = p;
            const char* p2; // last * pos
            const char* s2;
            bool star = false;

            while ( ( *s1 ) ||
                    ( *p1 == '\0' && star )) {

                if (*p1 == '*'){
                    p2 = p1++;
                    s2 = s1;
                    star = true;
                    continue;
                }
                
                if (*s1 == '\0' && *p1 == '\0'){
                    // 两个字符串都成功互相匹配完,提前结束
                    return true;
                }

                if (*s1 == *p1 || *p1 == '?'){
                    s1++;p1++;
                    continue;
                } else {
                    if (star){
                        p1 = p2 + 1;
                        s1 = ++s2;
                    } else {
                        return false;
                    }
                }
            }
            if (*s1 == '\0'){
                while (*p1 == '*') p1++;
            }
            return *s1 == '\0' && *p1 == '\0';
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
}
















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
