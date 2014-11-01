/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/01
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left
 * to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 *
 */

#include"../test/test.h"

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void travel(TreeNode *root,int level,vector<vector<int> > &res){
            if (root == NULL){
                return;
            }
            if (level >= res.size()){
                res.resize(1+level);
            }
            res[level].push_back(root->val);
            travel(root->left,level+1,res);
            travel(root->right,level+1,res);
        }

        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            vector<vector<int> > res;
            travel(root,0,res);


            for (int i=1;i<res.size();i+=2){
                int p = 0;
                int q = res[i].size() - 1;
                while (p <= q){
                    std::swap(res[i][p],res[i][q]);
                    p++;
                    q--;
                }
            }
            return res;
        }
};

void printRes(const char * str,vector<vector<int> > &res){
    cout<<str<<endl;
    cout<<"["<<endl;
    for (int i=0; i<res.size();i++){
        cout<<"  [";
        for (int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"  ]"<<endl;
    }
    cout<<"]"<<endl;
}

int main() {
    Solution s;

    const char * str = "3,9,20,#,#,15,7";
    TreeNode * root = OJTree(str);
    vector<vector<int> > res = s.zigzagLevelOrder(root);
    printRes(str,res);

    str = "1";
    root = OJTree(str);
    res = s.zigzagLevelOrder(root);
    printRes(str,res);

    str = "";
    root = OJTree(str);
    res = s.zigzagLevelOrder(root);
    printRes(str,res);
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
