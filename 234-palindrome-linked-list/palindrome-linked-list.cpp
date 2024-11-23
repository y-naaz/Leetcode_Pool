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
    private:
        ListNode* reverse(ListNode* head){
            ListNode* temp = head;
            ListNode* prev = NULL;
            ListNode*front =NULL;
            while(temp){
                front = temp->next;
                temp->next= prev;
                prev= temp; 
                temp = front ; 
            }
            return prev ; 
        }
public:
    bool isPalindrome(ListNode* head) {
        //step1:find the first middle of the linked list
        if(!head || !head->next) return head; 
        ListNode* slow = head ; 
        ListNode* fast = head ; 
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next ; 
            fast = fast->next->next;
        }
        ListNode* newHead= reverse(slow->next);
        ListNode* first = head ; 
        ListNode* second = newHead;
        while(second!=NULL){
            if(first->val!=second->val) return false ; 
            first = first->next;
            second= second->next;
        }
        return true ; 



    }
};