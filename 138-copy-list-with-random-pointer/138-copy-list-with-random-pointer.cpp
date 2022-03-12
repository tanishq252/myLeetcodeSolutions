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
        if(head == NULL){return head;}
        Node *curr = head;
        
        // loop to create a copied linked list connected to original one
        while(curr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        
        //initializing the random pointers of the copied linkedlist
        curr = head;
        while(curr){
            curr->next->random = (curr->random == NULL)? NULL : curr->random->next;
            curr = curr->next->next;
        }
        
        // here we are creating a list ans which will consist of copied values or the duplicate list
        Node *ans = head->next;
        curr = head->next;
        while(head){
            head->next = curr->next;
            head = head->next;
            if(head ==NULL) break;
            curr->next = head->next;
            curr = curr->next;
        }
        
        return ans;
    }
};