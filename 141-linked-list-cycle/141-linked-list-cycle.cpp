/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        if(head==NULL){return false;}
        ListNode *fast = head->next;
        ListNode *slow = head;
        if(fast==NULL){
            return false;
        }
        
        set<int> contains;
        while(fast!=slow && fast!=NULL && slow!=NULL){
            fast =(fast->next!=NULL)? fast->next->next:NULL;
            slow = slow->next;
        }
        return fast == slow;
    }
};