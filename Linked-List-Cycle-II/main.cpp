/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/03
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/linked-list-cycle-ii/
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (!head) return NULL;
            ListNode *p1 = head;
            ListNode *p2 = head->next;
            bool hasCycle = false;
            while (p1 && p2 && p2->next){
                if (p1 == p2){
                    hasCycle = true;
                    break;
                }
                p1 = p1->next;
                p2 = p2->next->next;
            }
            if (!hasCycle)
                return NULL;
            // 计算环的长度
            int count = 0;
            do {
                count++;
                p2 = p2->next;
            } while (p2 != p1);

            p1 = p2 = head;
            while (count) {
                p2 = p2->next;
                count--;
            }

            while (p1 != p2){
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
};

int main() {
    Solution s;
    cout<<s.detectCycle(printList(buildList("")))<<endl;
    cout<<s.detectCycle(printList(buildList("1")))<<endl;

    ListNode* list = buildList("1,2,3,4");
    cout<<s.detectCycle(printList(list))<<endl;

    ListNode* tmp = list;
    while (tmp->next){
        tmp = tmp->next;
    }
    tmp->next = list;
    cout<<s.detectCycle(list)<<endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
