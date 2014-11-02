/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/merge-two-sorted-lists/
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by
 * splicing together the nodes of the first two lists.
 *
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if (!l1) return l2;
            if (!l2) return l1;
            ListNode *head = NULL;
            ListNode *tail = NULL;
            while (l1 && l2){
                ListNode *n;
                if (l1->val <= l2->val){
                    n = l1;
                    l1 = l1->next;
                } else {
                    n = l2;
                    l2 = l2->next;
                }
                if (!head){
                    head = tail = n;
                } else {
                    n->next = NULL;
                    tail->next = n;
                    tail = n;
                }
            }

            if (l1){
                tail->next = l1;
            }
            if (l2){
                tail->next = l2;
            }
            return head;
        }
};

int main(){
    Solution s;

    printList(s.mergeTwoLists(printList(buildList("1,2,3")),printList(buildList(""))));
    cout<<"-----------------------"<<endl;
    printList(s.mergeTwoLists(printList(buildList("")),printList(buildList("1,2,3"))));
    cout<<"-----------------------"<<endl;
    printList(s.mergeTwoLists(printList(buildList("")),printList(buildList(""))));
    cout<<"-----------------------"<<endl;
    printList(s.mergeTwoLists(printList(buildList("1,2,3")),printList(buildList("4,5,6"))));
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
