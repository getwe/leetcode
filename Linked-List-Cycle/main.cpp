/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/03
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/linked-list-cycle/
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */
#include"../test/test.h"

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (!head) return false;
            ListNode *p1 = head;
            ListNode *p2 = head->next;
            while (p1 && p2 && p2->next){
                if (p1 == p2){
                    return true;
                }
                p1 = p1->next;
                p2 = p2->next->next;
            }
            return false;
        }
};

int main() {
    Solution s;
    cout<<s.hasCycle(printList(buildList("")))<<endl;
    cout<<s.hasCycle(printList(buildList("1")))<<endl;

    ListNode* list = buildList("1,2,3,4");
    cout<<s.hasCycle(printList(list))<<endl;

    ListNode* tmp = list;
    while (tmp->next){
        tmp = tmp->next;
    }
    tmp->next = list;
    cout<<s.hasCycle(list)<<endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
