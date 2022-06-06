/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> st;
        ListNode *t = headA;
        ListNode *t1 = headB;
        while(t!=NULL){
            if(st.find(t)==st.end()){st.insert(t);}
            t = t->next;
        }
        while(t1!=NULL){
            if(st.find(t1)!=st.end()){return t1;}
            t1 = t1->next;
        }
        return NULL;
    }
};