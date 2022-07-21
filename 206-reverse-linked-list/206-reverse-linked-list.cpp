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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode *current = head;
        ListNode *nextNode = NULL;
        while(current->next!=NULL){
            nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = head;
            head = nextNode;
        }
        return head;
    }
};