/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/10/30
 * @brief 
 *  
 **************************************************************************/
#include<iostream>
#include<vector>
/*
 *
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */
using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            using namespace std;

            if (s.length() == 0 || s[0] == '0'){
                return 0;
            }

            int PrevPrev = 1;
            int Prev = 1;
            int Curr = Prev;

            for (int i=0;i<s.length();i++){
                if (s[i] == '0'){
                    // 必须跟上一个字母进行搭配
                    if ( valid(s,i) ) {
                        Curr = PrevPrev;
                    } else {
                        return 0;
                    }
                } else {
                    if ( valid(s,i) ) {
                        // 跟前面数字可以组合,也可以不组合
                        Curr = PrevPrev + Prev;
                    } else {
                        // 跟前面数字没法组合
                        Curr = Prev;
                    }
                }
                PrevPrev = Prev;
                Prev = Curr;
           }
            return Curr;
        }

        bool valid(string s,int i){
            int num1 = s[i-1] - '0';
            int num2 = (s[i-1] - '0') * 10 + (s[i] - '0');
            return ( num1 == 1 || num1 == 2 ) &&
                (num2 >=1 && num2 <= 26);
        }
};



int main() {
    Solution s;
    std::cout<<"s\t0\t"<<s.numDecodings("")<<endl;
    std::cout<<"0\t0\t"<<s.numDecodings("0")<<endl;
    std::cout<<"1\t1\t"<<s.numDecodings("1")<<endl;
    std::cout<<"12\t2\t"<<s.numDecodings("12")<<endl;
    std::cout<<"27\t1\t"<<s.numDecodings("1")<<endl;
    std::cout<<"110\t1\t"<<s.numDecodings("110")<<endl;
    std::cout<<"101\t1\t"<<s.numDecodings("101")<<endl;
    std::cout<<"122\t3\t"<<s.numDecodings("122")<<endl;
    std::cout<<"1223\t5\t"<<s.numDecodings("1223")<<endl;
    std::cout<<"1250\t0\t"<<s.numDecodings("12250")<<endl;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
