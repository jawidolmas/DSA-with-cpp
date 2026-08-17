/**
 * 
 * 
 * 19. Remove Nth Node From End of List
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *p = head;
        ListNode *q = dummy;
        int i = 0;
        while(i<n){
            p = p->next;
            i++;
        }
        while(p!=nullptr){
            p = p->next;
            q = q->next;
        }
            ListNode *target = q->next;
            q->next = q->next->next;
            delete target;
            target = nullptr;
    return dummy->next;
    }
};