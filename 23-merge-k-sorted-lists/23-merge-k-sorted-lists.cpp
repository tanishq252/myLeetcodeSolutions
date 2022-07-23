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

    ListNode* mergeLists(ListNode* a, ListNode* b){
        ListNode *mergedList =NULL;

        if(a == NULL){return b;}
        if(b==NULL){return a;}
        
        if(a->val >= b->val){
            mergedList = b;
            mergedList->next = mergeLists(a, b->next);
        }else{
            mergedList = a;
            mergedList->next = mergeLists(a->next, b);
        }
        
        return mergedList;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* mergedKLists = lists[0];
        for(int i=1;i<lists.size();i++){
           mergedKLists  = mergeLists(mergedKLists, lists[i]);
        }
        return mergedKLists;
    }
};