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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *newlist = new ListNode();
        ListNode *ptr = newlist;
        int add = 0;
        while(t1&&t2){
            int sum = (t1->val+t2->val+add)%10;
            ListNode* newN = new ListNode(sum);
            ptr->next =newN;
            ptr = ptr->next;
            add = (t1->val+t2->val+add)/10;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
            int sum = (t1->val+add)%10;
            ListNode* newN = new ListNode(sum);
            ptr->next =newN;
            ptr = ptr->next;
            add = (t1->val+add)/10;
            t1 = t1->next;
        }
        while(t2){
            int sum = (t2->val+add)%10;
            ListNode* newN = new ListNode(sum);
            ptr->next =newN;
            ptr = ptr->next;
            add = (t2->val+add)/10;
            t2 = t2->next;
        }
        if(add>0){
            ListNode* newN = new ListNode(add);
            ptr->next =newN;
            ptr = ptr->next;
        }
        return newlist->next;
    }
};