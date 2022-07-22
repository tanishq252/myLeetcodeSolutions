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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL or head->next == NULL) return head;
        ListNode *partition1 = new ListNode(0); //smaller than x
        ListNode *partition2 = new ListNode(0); // greater than or equal to x
        ListNode *iterator1 = partition1;        
        ListNode *iterator2 = partition2;
        ListNode *temp = head;
        while(temp!=NULL){
            if(temp->val < x){
                iterator1->next = new ListNode(temp->val);
                iterator1 = iterator1->next;
            }else if(temp->val >= x){
                iterator2->next = new ListNode(temp->val);
                iterator2 = iterator2->next;
            }
            temp = temp->next;
        }
        iterator1->next = partition2->next;
        return partition1->next;
        
    }
};