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

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;        if(l2 == NULL) return l1;
        ListNode* newList;
        if(l1->val >= l2->val) {
            newList = l2;
            newList->next = merge(l1, l2->next);
        }else{
            newList = l1;
            newList->next = merge(l1->next, l2);
        }
        return newList;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        ListNode* ans = lists[0];
        for(int i=1;i<n;i++){
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};