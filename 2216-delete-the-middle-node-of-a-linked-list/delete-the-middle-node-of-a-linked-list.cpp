/**
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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        //We wants to put the slow  before the middle node therefore
        //skip the iteration of the slow for the first time 
        fast = fast->next->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nodeTobeDel = slow->next;
        slow->next = slow->next->next;
        delete nodeTobeDel;
        return head;
    }
};