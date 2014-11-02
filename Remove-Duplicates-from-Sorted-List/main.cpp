/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

#include"../test/test.h"

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (!head) return head;
            ListNode *p0 = head;
            ListNode *p1 = head->next;
            while (p1){
                if (p1->val == p0->val){
                    p0->next = p1->next;
                    delete p1;
                    p1 = p0->next;
                } else {
                    p0 = p1;
                    p1 = p1->next;
                }
            }
            return head;
        }
};

int main() {
    Solution s;
    printList(s.deleteDuplicates(printList(buildList("1,2,2,3,3,3,4,4"))));
    printList(s.deleteDuplicates(printList(buildList("1,1,1,1,1"))));
    printList(s.deleteDuplicates(printList(buildList(""))));
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
