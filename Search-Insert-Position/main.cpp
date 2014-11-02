/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/search-insert-position/
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return
 * the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */
#include"../test/test.h"

class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            int low = 0;
            int high = n-1;
            while (low <= high){
                int mid = (low+high)/2;
                if (target < A[mid]){
                    high = mid - 1;
                } else if (target > A[mid]){
                    low = mid + 1;
                } else {
                    return mid;
                }
            }
            return low;
        }
};

int main() {
    Solution s;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,0)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,1)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,2)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,3)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,4)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,5)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,6)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,7)<<endl;
    cout<<s.searchInsert(OJSplitArray("1,2,3,4,5,6"),6,8)<<endl;

}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
