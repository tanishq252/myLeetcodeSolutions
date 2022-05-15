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
    
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        ListNode *t = head;
        while(t!=NULL){
            v.push_back(t->val);
            t=t->next;
        }
        reverse(v.begin(), v.end());
        int i=1;
        int ans=0;
        for(int j=0;j<v.size();j++){
            ans+=(i*v[j]);
            i*=2;
        }
        return ans;
    }
};