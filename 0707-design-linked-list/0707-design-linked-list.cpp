class Node{
    public:
    int val; Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node *list = NULL;
    int length=0;
    
    MyLinkedList() {
        
    }
        void print(){
        Node *t=list;
            cout<<length<<": ";
        while(t){
            cout<<t->val<<" ";
            t = t->next;
        }
        cout<<"\n";
    }
    
    int get(int index) {
        if(length<=index) return -1;
        Node *t = list;
        for(int i=0;i<index;i++){
            t=t->next;
        }
        return t->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = list;
        list = newNode;
        length++;
    }
    
    void addAtTail(int val) {
        if(list == NULL){
            Node *newNode = new Node(val);
            newNode->next = list;
            list = newNode;
            length++;
        }else{
            Node *t = list;
            while(t->next!=NULL){
                t = t->next;
            }
            t->next = new Node(val);
            length++;  
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            Node *newNode = new Node(val);
            newNode->next = list;
            list = newNode;
            length++;
        }else{
            if(index == length){
                addAtTail(val);
            }else if(index<length){
                Node *t = list;
                for(int i=0;i<index-1;i++){
                    t=t->next;
                }
                Node *newN = new Node(val);
                newN->next = t->next;
                t->next = newN;
                length++;
            }
        }        
    }
    
    void deleteAtIndex(int index) {
        if(list == NULL or index>=length) return;
        if(index==0){
            list = list->next;length--;
        }else if(index<length){
            Node *t = list;
            for(int i=0;i<index-1;i++){
                t=t->next;
            }
            Node *t2 = t->next;
            t->next = t->next->next;
            delete t2;
            length--;
        }
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