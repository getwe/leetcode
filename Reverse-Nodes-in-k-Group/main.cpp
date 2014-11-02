/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it
 * is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */
#include"../test/test.h"

class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if (!head || !head->next|| k <= 1) return head;

            ListNode *p0 = head;
            ListNode *newHead = head;
            ListNode *newTail= NULL;
            while (p0) {
                ListNode *p1 = p0;
                for (int i=0;i<k;i++){
                    if (!p1){
                        return newHead;
                    }
                    p1 = p1->next;
                }
                // reverse
                ListNode *h = NULL;
                ListNode *t = NULL;
                while (p0 != p1){
                    ListNode *tmp = p0->next;
                    if (!t){
                        t = p0;
                    }
                    p0->next = h;
                    h = p0;
                    p0 = tmp;
                }
                t->next = p1;
                // append;
                if (newTail == NULL){
                    newHead = h;
                    newTail = t;
                } else {
                    newTail->next = h;
                    newTail = t;
                }
                p0 = p1;
            }
            return newHead;
        }
};

int main(){
    Solution s;
    printList(s.reverseKGroup(printList(buildList("1,2,3,4,5")),2));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1,2,3")),3));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1,2,3")),2));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1")),3));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1,2")),1));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1,2,3")),0));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1,2,3")),4));
    cout<<"-----------------------"<<endl;
    printList(s.reverseKGroup(printList(buildList("1,2,3,4,5,6,7,8")),3));
}



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
