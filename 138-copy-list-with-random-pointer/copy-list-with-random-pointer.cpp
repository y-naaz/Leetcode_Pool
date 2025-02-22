/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        Node* curr1 = head;
        while (curr1) {
            Node* newNode = new Node(curr1->val);
            newNode->next = curr1->next;
            curr1->next = newNode;
            curr1 = newNode->next;
        }
        curr1 = head;
        // Node* curr2 = head->next;
        while (curr1) {
            curr1->next->random = curr1->random == NULL ? NULL : curr1->random->next;
            curr1 = curr1->next->next;
        }
        Node* dummyNode = new Node(-1);
        Node* copylist = dummyNode;
        curr1 = head;
        while(curr1){
            copylist->next = curr1->next;
            curr1->next = curr1->next->next;
            copylist = copylist->next;
            curr1 = curr1->next; 
        }
        return dummyNode->next;
    }
};