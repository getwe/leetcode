/***************************************************************************
 * 
 * @file test.h
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/01
 * @brief 
 *  
 **************************************************************************/

#ifndef  __TEST_H_
#define  __TEST_H_

#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


vector<int> OJSplit(const char* c)
{
    vector<int> arr;
    if (!strlen(c)){
        return arr;
    }
    char * buf = new char[ strlen(c) ];
    strncpy(buf,c,strlen(c));
    
    const char * split = ","; 
    char * p; 
    p = strtok(buf,split); 
    while(p!=NULL) { 
        if (*p == '#'){
            arr.push_back('#');
        } else {
            arr.push_back(atoi(p));
        }
        p = strtok(NULL,split); 
    } 
    delete []buf;
    return arr;
}

int* OJSplitArray(const char* c)
{
    vector<int> arr = OJSplit(c);
    int * arr2 = new int[arr.size()];
    for (size_t i=0;i<arr.size();i++){
        arr2[i] = arr[i];
    }
    return arr2;
}

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

    vector<int> strvec = OJSplit(str);

    TreeNode* root = NULL;
    if (strvec.empty()){
        return root;
    }


    vector<int>::iterator iter = strvec.begin();

    int val = *iter;
    iter++;
    root = new TreeNode(val);

    queue<TreeNode*> Queue;
    Queue.push(root);

    while (!Queue.empty()){
        TreeNode* node = Queue.front();
        Queue.pop();


        if (node == NULL){
            continue;
        }
        if (iter == strvec.end()){
            //return root;
            break;
        }

        if (*iter == int('#')){
            node->left = NULL;
        } else {
            node->left = new TreeNode(*iter);
        }
        iter++;

        if (iter == strvec.end()){
            return root;
        }


        if (*iter == int('#')){
            node->right = NULL;
        } else {
            node->right = new TreeNode(*iter);
        }
        iter++;
        Queue.push(node->left);
        Queue.push(node->right);
    }
    return root;
}

ListNode* buildList(const char *c) {
    vector<int> num = OJSplit(c);

    ListNode * head = NULL;
    ListNode * tail = NULL;
    for (size_t i=0;i<num.size();i++){
        ListNode * node = new ListNode(num[i]);
        if (head == NULL){
            head = tail = node;
            continue;
        }
        tail->next = node;
        tail = tail->next;
    }
    return head;
}

ListNode* printList(ListNode *head){
    if (!head){
        cout<<"<nil>"<<endl;
        return head;
    }
    ListNode * h = head;
    while(h){
        cout<<h->val<<"\t";
        h = h->next;
    }
    cout<<endl;
    return head;
}














#endif  //__TEST_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
