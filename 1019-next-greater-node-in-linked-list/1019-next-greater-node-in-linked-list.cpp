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
    int findNextGreater(int x, vector<int> &nodes){
        if(*max_element(nodes.begin()+x, nodes.end()) <= nodes[x]) return 0;
        for(int i=x;i<nodes.size();i++){
            if(nodes[i] > nodes[x]){return nodes[i];}
        }
        return 0;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodes;        
        vector<int> ans;
        ListNode *temp = head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i=0;
        while(temp!=NULL){
            ans.push_back(findNextGreater(i, nodes));
            i++; temp = temp->next;
        }
        // ans.push_back(0);
        return ans;
        

    }
};