/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/10/31
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/reorder-list/
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(string num) {
    ListNode * head = NULL;
    ListNode * tail = NULL;
    for (int i=0;i<num.length();i++){
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

void printList(ListNode *head){
    while(head){
        cout<<char(head->val)<<"\t";
        head = head->next;
    }
    cout<<endl;
}


class Solution {
    public:
        void reorderList(ListNode *head) {
            ListNode *tmp = NULL;

            int listLength = 0;
            // cal length
            tmp = head;
            while(tmp){
                listLength++;
                tmp = tmp->next;
            }
            if (listLength == 0){
                return;
            }

            ListNode *list1 = NULL;
            ListNode *list2 = NULL;

            // split
            list1 = tmp = head;
            int i = 0;
            while(i < int((listLength-1)/2)){
                tmp = tmp->next;
                i++;
            }
            list2 = tmp->next;
            tmp->next = NULL;

            // revert list2
            tmp = list2;
            list2 = NULL;
            while (tmp) {
                ListNode *next = tmp->next;
                tmp->next = list2;
                list2 = tmp;
                tmp = next;
            }

            // merge
            ListNode *tail = NULL;
            int flag = 0;
            while (list1 || list2){
                ListNode *node = NULL;
                if (flag % 2 == 0){
                    node = list1;
                    list1 = list1->next;
                } else {
                    node = list2;
                    list2 = list2->next;
                }
                flag++;
                node->next = NULL;
                if (tail != NULL){
                    tail->next = node;
                }
                tail = node;
            }
        }
};

int main() {
    Solution s;
    ListNode *list = buildList("abcdef");
    printList(list);
    s.reorderList(list);
    printList(list);

    ListNode *list2 = buildList("");
    printList(list2);
    s.reorderList(list2);
    printList(list2);

}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
