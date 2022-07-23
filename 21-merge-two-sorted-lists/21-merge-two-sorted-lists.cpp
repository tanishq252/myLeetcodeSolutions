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
    ListNode *mergeLists(ListNode *list1, ListNode *list2){
        ListNode *mergedList = NULL;
        
        if(list1 == NULL){return list2;}
        if(list2 == NULL){return list1;}
        
        if(list1->val < list2->val){
            mergedList = list1;
            mergedList->next = mergeLists(list1->next, list2);
        }else{
            mergedList = list2;
            mergedList->next = mergeLists(list1, list2->next);
        }
        
        return mergedList;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeLists(list1, list2);
    }
};