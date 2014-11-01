/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/01
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/single-number/
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using
 * extra memory?
 */
#include<iostream>
using namespace std;

class Solution {
    public:
        int singleNumber(int A[], int n) {
            int r = 0;
            for (int i = 0; i < n;i++){
                r ^= A[i];
            }
            return r;
        }
};

int main() {
    Solution s;

    int arr1[] = {1,-3,-3,2,3,4,5,1,2,3,4};
    cout<<s.singleNumber(arr1,sizeof(arr1)/sizeof(int))<<endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
