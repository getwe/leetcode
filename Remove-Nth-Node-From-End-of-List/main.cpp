/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes 1->2->3->5.
 *    Note:
 *    Given n will always be valid.
 *    try to do this in one pass.
 */

#include"../test/test.h"

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            if (!head) return head;

            ListNode *p1,*p2,*p3;
            p1 = p2 = p3 = head;

            //Given n will always be valid.
            while (n){
                p3 = p3->next;
                n--;
            }
            while (p3){
                p1 = p2;
                p2 = p2->next;
                p3 = p3->next;
            }

            if (p1 != p2){
                p1->next = p2->next;//del p2
            } else {
                // first node : p1 == p2 == head
                head = p2->next;
            }
            return head;
        }
};

int main(){
    Solution s;

    printList(s.removeNthFromEnd(printList(buildList("")),0));
    printList(s.removeNthFromEnd(printList(buildList("1,2,3,4,5")),1));
    printList(s.removeNthFromEnd(printList(buildList("1,2,3,4,5")),2));
    printList(s.removeNthFromEnd(printList(buildList("1,2,3,4,5")),3));
    printList(s.removeNthFromEnd(printList(buildList("1,2,3,4,5")),4));
    printList(s.removeNthFromEnd(printList(buildList("1,2,3,4,5")),5));
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
