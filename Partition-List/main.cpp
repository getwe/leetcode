/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/partition-list/
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes
 * greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */

#include"../test/test.h"

class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode* l1Head = NULL;
            ListNode* l1Tail = NULL;
            ListNode* l2Head = NULL;
            ListNode* l2Tail = NULL;
            while (head){
                ListNode * tmp = head->next;
                head->next = NULL;

                if (head->val < x){
                    if (l1Head == NULL){
                        l1Head = l1Tail = head;
                    } else {
                        l1Tail->next = head;
                        l1Tail = l1Tail->next;
                    }
                } else {
                    if (l2Head == NULL){
                        l2Head = l2Tail = head;
                    } else {
                        l2Tail->next = head;
                        l2Tail = l2Tail->next;
                    }
                }
                head = tmp;
            }
            if (l1Head){
                l1Tail->next = l2Head;
                return l1Head;
            }
            return l2Head;
        }
};

int main(){
    Solution s;
    printList(s.partition(printList(buildList("")),3));
    printList(s.partition(printList(buildList("1")),3));
    printList(s.partition(printList(buildList("5")),3));
    printList(s.partition(printList(buildList("1,4,3")),3));
    printList(s.partition(printList(buildList("1,4,3,2,5,2")),3));
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
