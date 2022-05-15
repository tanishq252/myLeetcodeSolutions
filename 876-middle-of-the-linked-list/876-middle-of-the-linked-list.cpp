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
    ListNode* middleNode(ListNode* head) {
        ListNode *t = head;
        int l=0;
        while(t!=NULL){
            t=t->next;
            l++;
        }
        cout<<l;
        t = head;
        int x = l/2;
        while(x--){
            t=t->next;
        }
        return t;
    }
};