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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL){
            return head;
        }
        ListNode *current = head;
        int tLeft = left;
        int count = right-left;
        if(!count) return head;
        left--;
        // cout<<left;
        // if(left){
            ListNode *prev=NULL;
        // }
        while(left--){
            cout<<"next"<<" ";
            prev = current;
            current = current->next;
        }
        ListNode *tempHead = current;
        ListNode *nextNode = NULL;
        while(tempHead->next!=NULL and count--){
            nextNode = tempHead->next;
            tempHead->next = nextNode->next;
            nextNode->next = current;
            current = nextNode;
        }
        // cout<<current->next->val;
        cout<<left<<" ";
        if(tLeft!=1){
            prev -> next = current;
            cout<<"sdlmsvfvfv";}
        return (tLeft!=1) ? head:current;
    }
};