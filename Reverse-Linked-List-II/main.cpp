/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/reverse-linked-list-ii/
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

#include"../test/test.h"

class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode *p0 = head;
            ListNode *p1 = head;
            for (int i=1;i<m;i++){
                p0 = p1;
                p1 = p1->next;
            }
            ListNode *tail = p1;
            for (int i=m;i<n;i++){
                ListNode *p2 = tail->next;
                tail->next = p2->next;
                p2->next = p1;
                p1 = p2;
            }
            if (m==1){
                return p1;
            } else {
                p0->next = p1;
            }
            return head;
        }
};

int main(){
    Solution s;

    printList(s.reverseBetween(printList(buildList("1,2,3,4,5")),1,5));
    cout<<"-----------------------"<<endl;
    printList(s.reverseBetween(printList(buildList("1,2,3,4,5")),2,5));
    cout<<"-----------------------"<<endl;
    printList(s.reverseBetween(printList(buildList("1,2,3,4,5")),3,5));
    cout<<"-----------------------"<<endl;
    printList(s.reverseBetween(printList(buildList("1,2,3,4,5")),4,5));
    cout<<"-----------------------"<<endl;
    printList(s.reverseBetween(printList(buildList("1,2,3,4,5")),5,5));
    cout<<"-----------------------"<<endl;
    printList(s.reverseBetween(printList(buildList("1,2,3,4,5")),2,4));

}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
