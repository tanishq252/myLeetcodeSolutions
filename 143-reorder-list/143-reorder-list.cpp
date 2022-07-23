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
    void reorderList(ListNode* head) {
        vector<int> nodes;
        ListNode *temp = head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=0;
        int n = nodes.size();
        while(temp!=NULL){
            temp->val = nodes[i];
            if(temp->next!=NULL){
                temp->next->val = nodes[n-i-1];
                temp=temp->next->next;i++;
            }else{
                temp = temp->next;
            }
            
        }
        
    }
};