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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prev = head;
        int len = 1;
        if(head==NULL || head->next==NULL){return head;}
        while(temp->next){
            len++;            
            temp = temp->next;
        }
        temp->next = head;
        k%=len;
        temp = head;
        int j = (len-k);
        while(j--){
            prev= temp;
            temp = temp->next;
        }
        head = temp;
        prev->next = NULL;
        return head;
    }
};