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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> nodes;
        ListNode *temp = head;
        int n=0;
        // size of list
        while(temp!=NULL){
            temp = temp->next;n++;
        }
        vector<int> sizes(k, n/k);
        for(int i=0;i<n%k;i++){
            sizes[i]++;
        }
        temp = head;
        for(auto i:sizes){
            ListNode *newList = new ListNode(-1);            
            ListNode *newTemp = newList;

            while(i--){
                newTemp->next = new ListNode(temp->val);
                newTemp = newTemp->next;
                temp = temp->next;
            }
            nodes.push_back(newList->next);

        }
        return nodes;
    }
};