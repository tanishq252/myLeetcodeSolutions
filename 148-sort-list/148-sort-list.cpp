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
    void splitList(ListNode *head, ListNode **frontPart, ListNode **backPart){
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        *frontPart = head;
        *backPart = slow->next;
        slow->next = NULL;
    }
    
    void mergeSort(ListNode **head){
        ListNode *a, *b;
        
        if((*head)->next == NULL or (*head) == NULL){
            return;
        }
        
        splitList(*head, &a, &b);
        
        mergeSort(&a);
        mergeSort(&b);
        
        *head = mergeLists(a, b);
        
    }
    
    ListNode* mergeLists(ListNode *a, ListNode *b){
        ListNode *mergedList = NULL;
        
        if(a == NULL){return b;}
        if(b == NULL){return a;}
        
        if(a->val < b->val){
            mergedList = a;
            mergedList->next = mergeLists(a->next, b);
        }else{
            mergedList = b;
            mergedList->next = mergeLists(a, b->next);
        }
        
        return mergedList;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next==NULL) return head;
        mergeSort(&head);
        return head;
    }
};