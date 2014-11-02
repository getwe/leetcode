/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/


/*
 * https://oj.leetcode.com/problems/add-two-numbers/
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in
 * reverse order and each of their nodes contain a single digit. Add the two numbers and return it
 * as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *head = NULL;
            ListNode *tail = NULL;
            ListNode *tmp  = NULL;
            int addOne = 0;

            while (l1 && l2){
                l1->val += (l2->val + addOne);
                addOne = (l1->val>=10)?1:0;
                l1->val = l1->val % 10;

                tmp = l1->next;
                // insert
                if (!head){
                    head = tail = l1;
                } else{
                    l1->next = NULL;
                    tail->next = l1;
                    tail = l1;
                }
                //
                l1 = tmp;
                l2 = l2->next;
            }

            ListNode *node = l1?l1:l2;

            while (node) {
                tmp = node->next;
                node->next = NULL;
                tail->next = node;
                tail = node;
                node = tmp;
                if (addOne){
                    tail->val++;
                    addOne = (tail->val>=10)?1:0;
                    tail->val = tail->val % 10;
                }
            }

            if (addOne){
                ListNode * n = new ListNode(addOne);
                tail->next = n;
                tail = n;
            }

            return head;
        }
};

int main() {
    Solution s;

    printList(s.addTwoNumbers(printList(buildList("2,4,3")),
                              printList(buildList("5,6,4"))));
    cout<<endl;

    printList(s.addTwoNumbers(printList(buildList("")),
                              printList(buildList("5,6,4"))));
    cout<<endl;

    printList(s.addTwoNumbers(printList(buildList("2,4,3")),
                              printList(buildList(""))));
    cout<<endl;

    printList(s.addTwoNumbers(printList(buildList("5")),
                              printList(buildList("5,6,4"))));
    cout<<endl;

    printList(s.addTwoNumbers(printList(buildList("2,4")),
                              printList(buildList("6"))));
    cout<<endl;

    printList(s.addTwoNumbers(printList(buildList("5")),
                              printList(buildList("5"))));
    cout<<endl;

    printList(s.addTwoNumbers(printList(buildList("1")),
                              printList(buildList("9,9"))));
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
