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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        map<int, int> m;
        while(temp){
            m[temp->val]++;
            temp = temp->next;
        }
        ListNode *newList = NULL;
        temp = head;
        for(int i=-100;i<=100;i++){
            if(m[i]>=1){
                ListNode* newNode = new ListNode;
                newNode->val= i;
                newNode->next = NULL;
                if(newList ==  NULL){
                    newList = newNode;
                }
                else{
                    ListNode *ptr = newList;
                    while(ptr->next!=NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = newNode;
                }
            }
        }
        return newList;
    }
};