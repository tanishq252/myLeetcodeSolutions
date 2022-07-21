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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        vector<int> v, vr;
        ListNode *temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        vr = v;
        reverse(v.begin(), v.end());
        return v == vr;
    }
};