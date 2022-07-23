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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp2 = list2;        
        ListNode *temp1 = list1;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        int i=0;
        while(i<b){
            temp1=temp1->next;
            i++;
        }
        temp1=temp1->next;
        temp2->next = temp1;
        ListNode *temp3 = list1;
        i=1;
        while(i<a){
            temp3=temp3->next;i++;
        }
        temp3->next = list2;
        return list1;

    }
};