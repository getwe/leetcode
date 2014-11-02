/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
 * numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode *t= NULL;
            ListNode *h = NULL;
            ListNode *p0 = head;
            while (p0){
                ListNode *p1 = p0;
                while (p1 && p1->val == p0->val){
                    p1 = p1->next;
                }

                if (p0->next == p1){ // keep the node
                    p0->next = NULL;
                    if (h == NULL){
                        h = t = p0;
                    } else {
                        t->next = p0;
                        t = t->next;
                    }
                    p0 = p1;
                } else { // delete nodes
                    while(p0 != p1){
                        ListNode *tmp = p0;
                        p0 = p0->next;
                        delete tmp;
                    }
                }
            }
            return h;
        }
};

int main() {
    Solution s;
    printList(s.deleteDuplicates(printList(buildList(""))));
    printList(s.deleteDuplicates(printList(buildList("1"))));
    printList(s.deleteDuplicates(printList(buildList("1,1"))));
    printList(s.deleteDuplicates(printList(buildList("1,1,1,1,1"))));
    printList(s.deleteDuplicates(printList(buildList("1,2,2,3,3,3,4,4"))));
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
