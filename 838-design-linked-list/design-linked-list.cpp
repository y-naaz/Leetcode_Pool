class Node{
    public:
        int data ;
        Node* next ; 
        Node(int data){
            this->data = data ; 
           this->next = NULL;
        }
};
class MyLinkedList {
    

public:
    Node*head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node* ptr = head;
        int pos = 0 ; 
        while(ptr){
            if(pos==index){
                return ptr->data;
            }
            ptr= ptr->next;
            pos++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp ->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {

        Node* temp = new Node(val);
        
        if(!head){
            head = temp;
            return ;
        }
        temp->next = NULL;
        Node*ptr = head ; 
        while(ptr->next){
            ptr=ptr->next ;
        }
        ptr->next = temp;
    }
    
    void addAtIndex(int index, int val) { 
    if(index==0){
        return addAtHead(val);
    }
        int pos = 0 ; 
        Node* newNode = new  Node(val);
        Node*ptr = head ; 
        while(ptr && pos<index-1){
            ptr= ptr->next;
            pos++;
        }
        if(!ptr) return;
        newNode->next = ptr->next ; 
        ptr->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if(!head) return ; 
        if(index==0){
            Node* temp = head ; 
            head = head ->next ;
            delete temp;
            return; 
        }
        int pos = 0 ; 
        Node*ptr = head ; 
        while(ptr&& pos<index-1){

            ptr= ptr->next;
            pos++;
        }
        if(!ptr || !ptr->next) return ;
        Node* temp = ptr->next;
        ptr->next = ptr->next->next;
        temp->next = NULL;
        delete temp ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */