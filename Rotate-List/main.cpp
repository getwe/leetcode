/***************************************************************************
 * 
 * @file main.cpp
 * @author Hong Gengwei(honggengwei@gmail.com)
 * @date 2014/11/02
 * @brief 
 *  
 **************************************************************************/

/*
 * https://oj.leetcode.com/problems/rotate-list/
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */
#include"../test/test.h"
class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (!head) return head;
            // count the length and make a cycle list;
            int length = 0;
            ListNode *p0 = head;
            while (p0){
                length++;
                if (p0->next == NULL){
                    p0->next = head;
                    break;
                }
                p0 = p0->next;
            }
            ListNode *tail = head;
            int index = length - (k%length) - 1;
            while (index > 0){
                tail = tail->next;
                index--;
            }
            head = tail->next;
            tail->next = NULL;
            return head;
        }
};

int main(){
    Solution s;
    printList(s.rotateRight(printList(buildList("")),3));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1")),3));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2")),1));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3")),0));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3")),1));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3")),2));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3")),3));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3")),4));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3,4,5")),2));
    cout<<"-----------------------"<<endl;
    printList(s.rotateRight(printList(buildList("1,2,3,4,5")),7));
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
