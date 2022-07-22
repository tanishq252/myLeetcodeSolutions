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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *, int> mp;
        int i=0;     
        ListNode *temp = head;
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp[temp] = i++;
            temp = temp->next;
        }
        return NULL;
            
    }
};