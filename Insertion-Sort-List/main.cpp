/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/03
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/insertion-sort-list/
 *
 * Sort a linked list using insertion sort.
 *
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *insertionSortList(ListNode *head) {
            ListNode *newHead = NULL;
            while (head){
                ListNode *next = head->next;
                ListNode *insertPos = newHead;
                ListNode *prevPos = insertPos;
                while (insertPos && insertPos->val <= head->val){
                    prevPos = insertPos;
                    insertPos = insertPos->next;
                }
                if (insertPos == newHead){
                    head->next = newHead;
                    newHead = head;
                } else {
                    head->next = insertPos;
                    prevPos->next = head;
                }
                head = next;
            }
            return newHead;
        }
};

int main() {
    Solution s;
    printList(s.insertionSortList(printList(buildList(""))));
    printList(s.insertionSortList(printList(buildList("1"))));
    printList(s.insertionSortList(printList(buildList("3,1"))));
    printList(s.insertionSortList(printList(buildList("3,1,2"))));
    printList(s.insertionSortList(printList(buildList("8,7,6,5,4,3,2,1"))));
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
