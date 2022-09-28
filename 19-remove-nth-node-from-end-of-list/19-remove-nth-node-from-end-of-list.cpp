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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp->next;len++;
        }
        temp = head;
        if(n == len){
            return temp->next;
        }
        int k = len - n;
        len = 1;
        while(temp){
                        cout<<temp->val<<" "<<len<<"\n";

            if(len == k){
                // ListNode *t = temp->next;
                temp->next = temp->next->next;len++;
                // delete t;
            }else{
                temp = temp->next;
                len++;
            }
        }
        return head;
    }
};