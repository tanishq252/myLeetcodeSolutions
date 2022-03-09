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
        temp = head;
        ListNode* t = head;
        ListNode* newL = NULL;

        while(t){
            if(m[t->val] == 1){
                ListNode *tt = new ListNode;
                tt->val = t->val;
                tt->next = NULL;
                if(newL == NULL){newL = tt;}
                else{
                    ListNode* trave = newL;
                    while(trave->next!=NULL){
                        trave = trave->next;
                    }
                    trave->next = tt;
                }
            }
            t = t->next;
        }

        return newL;
    }
};