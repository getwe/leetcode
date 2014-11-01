/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/10/31
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/symmetric-tree/
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */
#include<iostream>
#include<vector>
#include<queue>
#include "../test/test.h"

using namespace std;
/*
 * 最初思路是层级递归后看结果是否对称,折腾好久各种小问题没搞定
 * 最后才看到这种解法,原来只需要逻辑性旋转一下两个节点即可
 */
class Solution {
    public:
        bool isSymmetric(TreeNode *left,TreeNode *right){
            if (left == NULL && right == NULL) return true;
            if (left == NULL || right == NULL) return false;
            return (left->val == right->val) &&
                (isSymmetric(left->left,right->right)) &&
                (isSymmetric(left->right,right->left));
        }
        bool isSymmetric(TreeNode *root) {
            if (root == NULL){
                return true;
            }
            return isSymmetric(root->left,root->right);
        }
};

int main() {
    Solution s;
    const char * str;

    str = "1,2,3,#,#,4,#,#,5";
    cout<<str<<"\t"<<s.isSymmetric(OJTree(str))<<"\tfalse"<<endl;

    str = "3,4,4,5,#,#,5,6,#,#,6";
    cout<<str<<"\t"<<s.isSymmetric(OJTree(str))<<"\ttrue"<<endl;

    str = "";
    cout<<str<<"\t"<<s.isSymmetric(OJTree(str))<<"\ttrue"<<endl;

    str = "1,2,3";
    cout<<str<<"\t"<<s.isSymmetric(OJTree(str))<<"\tfalse"<<endl;

    str = "2,3,3,4,5,5,4,#,#,8,9,#,#,9,8";
    cout<<str<<"\t"<<s.isSymmetric(OJTree(str))<<"\tfalse"<<endl;

    str = "1,2";
    cout<<str<<"\t"<<s.isSymmetric(OJTree(str))<<"\tfalse"<<endl;
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
