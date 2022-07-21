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
    ListNode* oddEvenList(ListNode* head) {
      ListNode *oddList = new ListNode(0);
      ListNode *evenList = new ListNode(0);
        ListNode *tempodd = oddList;
        ListNode *tempeven = evenList;
        ListNode *temp = head;
        int i=0;
        while(temp!=NULL){
            if((i%2)==0){
                tempeven->next = new ListNode(temp->val);
                tempeven = tempeven->next;
            }
            else if((i%2)!=0){
                tempodd->next = new ListNode(temp->val);
                tempodd = tempodd->next;
            }
            i++;
            temp = temp->next;
        }

        tempeven->next = oddList->next;
        return evenList->next;

    }
};