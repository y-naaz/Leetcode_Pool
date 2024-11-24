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
    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next) return head ;
        ListNode* slow = head ; 
        ListNode* fast = head->next ; //because we wants first middle;
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
        }
        ListNode*middle = slow; 
        return middle;
    }
    ListNode* merge(ListNode* t1, ListNode* t2){
        if(!t1 && !t2) return NULL;
        if(!t1) return t2;
        if(!t2) return t1;
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(t1 && t2){
            if(t1->val<t2->val){
                temp->next = t1;
                t1=t1->next;
            }
            else{
                temp->next = t2 ; 
                t2=t2->next;
            }
            temp = temp->next;
        }
        if(t1) temp->next=t1;
        else temp->next = t2;
        return dNode->next;
    }
    ListNode* mergeSort(ListNode*head){
        if(!head || !head->next) return head ;
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};