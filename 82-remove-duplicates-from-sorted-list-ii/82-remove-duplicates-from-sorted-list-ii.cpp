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
    ListNode* deleteDuplicates(ListNode* head) {
        // temp to traverse through the linked list
        ListNode *temp = head;
        // map to store frequencies of linked list
        map<int, int> m;
        // traversing through linkedlist to record data 
        while(temp){
            m[temp->val]++;
            temp = temp->next;
        }
        
        // ListNode t is created to traverse through the given list again to check frequencies
        ListNode* t = head;
        // new List to return values as per the problem statement
        ListNode* newL = NULL;

        while(t){
            // checking whether the value of current node is appeared only once
            if(m[t->val] == 1){
                //creating a new instance of node to initialize the value and point it to NULL
                ListNode *tt = new ListNode;
                tt->val = t->val;
                tt->next = NULL;
                // if it is first node then making it head of the list
                if(newL == NULL){newL = tt;}
                else{
                    // if the list consists of head then we have to traverse to last and append the data to tail as list is already sorted
                    ListNode* trave = newL;
                    while(trave->next!=NULL){
                        trave = trave->next;
                    }
                    trave->next = tt;
                }
            }
            // moving to the next node
            t = t->next;
        }

        return newL;
    }
};