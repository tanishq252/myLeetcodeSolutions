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
        long long int n1=0,n2=0;
        long long int j1=1, j2=1;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *newlist = new ListNode();
        ListNode *ptr = newlist;
        int add = 0, add_now =0;
        while(t1&&t2){
            // cout<<t1->val<<" "<<t2->val;
            
            int sum = (t1->val+t2->val+add)%10;
            cout<<sum<<" ";
            ListNode* newN = new ListNode(sum);
            ptr->next =newN;
            ptr = ptr->next;
            add = (t1->val+t2->val+add)/10;
            // cout<<add;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
           // cout<<t1->val;
            int sum = (t1->val+add)%10;
            cout<<sum<<" ";
            ListNode* newN = new ListNode(sum);
            ptr->next =newN;
            ptr = ptr->next;
            add = (t1->val+add)/10;
            t1 = t1->next;
        }
        while(t2){
           // cout<<t2->val;
            int sum = (t2->val+add)%10;
            cout<<sum<<" ";
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