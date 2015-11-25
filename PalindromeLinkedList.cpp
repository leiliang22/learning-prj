/**********************************************************
 * File name: PalindromeLinkedList.cpp
 * Author: lei.liang
/**********************************************************

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode* p = head;
        int size = 0;
        while (p) {
            p = p->next;
            ++size;
        }
        
        size = size>>1;
        ListNode** pp = NULL;
        p = head;
        while (size--) {
            p = p->next;
        }
        ListNode* pr = p->next;
        pp = &(p->next);
        while (pr) {
            *pp = pr->next;
            pr->next = p;
            p = pr;
            pr = *pp;
        }
        pr = p;
        
        while (pr) {
            if (head->val != pr->val) return false;
            head = head->next;
            pr = pr->next;
        }
        
        return true;
    }
};