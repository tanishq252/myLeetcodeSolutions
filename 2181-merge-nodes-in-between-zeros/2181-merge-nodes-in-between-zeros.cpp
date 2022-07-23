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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head;
        temp = temp->next;
        ListNode *newList = new ListNode(-1);
        ListNode *newTemp = newList;
        int sum =0;
        while(temp!=NULL){
            if(temp->val == 0){
                newTemp->next = new ListNode(sum);
                newTemp = newTemp->next;
                sum=0;
            }else{
                sum+= (temp->val);
            }
            temp = temp->next;
        }
        return newList->next;
    }
};