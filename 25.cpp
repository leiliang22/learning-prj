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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode st;
        ListNode** tmp = &(st.next);

        // reset 
        ListNode *p=head, *q=head;

        while (q != nullptr) {
            int cnt = 0;
            while (cnt < k && q != nullptr) {
                p = q;
                q = q->next;
                ++cnt;
            }
            
            p->next = nullptr;
            if (cnt == k) 
                *tmp = reverse(head);
            else 
                *tmp = head;

            tmp = &(head->next);
            head = q;
        }
        return st.next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *p=nullptr, *q=head;

        while (q != nullptr) {
            q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
        return p;
    }
};
