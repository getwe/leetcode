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
using namespace std;


/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* OJTree(const char *str){
    /*
     *
     *   1
     *  / \
     * 2   3
     *    /
     *   4
     *    \
     *     5
     *
     * 1,2,3,#,#,4,#,#,5
     *
     */
    TreeNode* root = NULL;
    if (*str == '\0'){
        return root;
    }

    int val = *str++;
    root = new TreeNode(val);

    queue<TreeNode*> Queue;
    Queue.push(root);

    while (Queue.size()){
        TreeNode* node = Queue.front();
        Queue.pop();

        if (node == NULL){
            continue;
        }
        if (*str == '\0'){
            return root;
        }

        if (*str == '#'){
            node->left = NULL;
        } else {
            node->left = new TreeNode(*str);
        }
        str++;
        if (*str == '#'){
            node->right = NULL;
        } else {
            node->right = new TreeNode(*str);
        }
        str++;
        Queue.push(node->left);
        Queue.push(node->right);
    }
    return root;
}


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

    cout<<"123##4##5"<<"\t"<<s.isSymmetric(OJTree("123##4##5"))<<"\tfalse"<<endl;
    cout<<"3445##56##6"<<"\t"<<s.isSymmetric(OJTree("3445##56##6"))<<"\ttrue"<<endl;
    cout<<""<<"\t"<<s.isSymmetric(OJTree(""))<<"\ttrue"<<endl;
    cout<<"123"<<"\t"<<s.isSymmetric(OJTree("123"))<<"\tfalse"<<endl;
    cout<<"2334554##89##98"<<"\t"<<s.isSymmetric(OJTree("2334554##89##98"))<<"\tfalse"<<endl;
    cout<<"12"<<"\t"<<s.isSymmetric(OJTree("12"))<<"\tfalse"<<endl;
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
