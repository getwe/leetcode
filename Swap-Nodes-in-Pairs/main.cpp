/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/03
 * @brief 
 *  
 **************************************************************************/

/* 
 * https://oj.leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only
 * nodes itself can be changed.
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (!head || !head->next) return head;
            ListNode *newHead = NULL;
            ListNode *newTail = NULL;
            while (head){
                if (head->next){
                    ListNode *node = head->next;
                    ListNode *tmp = node->next;

                    // swap
                    head->next = NULL;
                    node->next = head;

                    // append
                    if (newTail == NULL){
                        newHead = node;
                        newTail = head;
                    } else {
                        newTail->next = node;
                        newTail = head;
                    }

                    head = tmp;
                } else {
                    newTail->next = head;
                    head->next = NULL;
                    head = NULL;
                }
            }
            return newHead;
        }
};

int main() {
    Solution s;
    printList(s.swapPairs(printList(buildList(""))));
    printList(s.swapPairs(printList(buildList("1"))));
    printList(s.swapPairs(printList(buildList("1,2"))));
    printList(s.swapPairs(printList(buildList("1,2,3"))));
    printList(s.swapPairs(printList(buildList("1,2,3,4"))));
    printList(s.swapPairs(printList(buildList("1,2,3,4,5"))));
}
















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
