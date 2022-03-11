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
    ListNode* rotateRight(ListNode* head, int k) {
        // passed all test cases with runtime 4 ms
        // ListNode *temp = head;
        // vector<int> v1;
        // vector<int> v2;
        // ListNode *newList = new ListNode();
        // ListNode *ptr = newList;
        // while(temp){
        //     v1.push_back(temp->val);            
        //     temp = temp->next;
        // }
        // int n = v1.size();
        // if(n == 0){return head;}
        // k%=n;
        // for(int i=n-k;i<n;i++){
        //     v2.push_back(v1[i]);
        // }
        // for(int i=0;i<n-k;i++){
        //     v2.push_back(v1[i]);
        // }
        // for(int i=0;i<v2.size();i++){
        //     ListNode *newNode = new ListNode(v2[i]);
        //     ptr->next = newNode;
        //     ptr = ptr->next;
        // }
        // return newList->next;
        
        ListNode *temp = head;
        ListNode *prev = head;
        int len = 1;
        if(head==NULL || head->next==NULL){return head;}
        ListNode *newList = new ListNode();
        ListNode *ptr = newList;
        while(temp->next){
            len++;            
            temp = temp->next;
        }
        temp->next = head;
        cout<<len<<" ";
        k%=len;
        cout<<k;
        temp = head;
        int j = (len-k);
        while(j--){
            prev= temp;
            temp = temp->next;
        }
        head = temp;
        prev->next = NULL;
        return head;
    }
};