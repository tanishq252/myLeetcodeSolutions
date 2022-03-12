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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *newList = new ListNode();
        ListNode *ptr = newList;
        int len = 0;
        vector<int> v;
        while(temp){
            len++;
            v.push_back(temp->val);
            temp = temp->next;
        }
        cout<<len;
        temp = head;
        for(int i=0;i<len;i++){
            if(i!=(len - n)){ListNode *newNode = new ListNode(temp->val);
            ptr->next = newNode;
            ptr = ptr->next;}
            temp = temp->next;
        }
        return newList->next;
    }
};