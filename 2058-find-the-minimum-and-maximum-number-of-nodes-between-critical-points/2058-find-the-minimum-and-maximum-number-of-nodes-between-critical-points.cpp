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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn = INT_MAX;
        vector<int> criticalPoints;
        ListNode *temp = head;
        ListNode *prev = head;
        temp = temp->next;
        int i=2;
        while(temp->next!=NULL){
            if(temp->val > prev->val and temp->val > temp->next->val){
                criticalPoints.push_back(i);
                if(criticalPoints.size() > 1){
                    mn = min(mn, criticalPoints[criticalPoints.size()-1]-criticalPoints[criticalPoints.size()-2]);
                }
            }else if(temp->val < prev->val and temp->val < temp->next->val){
                criticalPoints.push_back(i);
                if(criticalPoints.size() > 1){
                    mn = min(mn, criticalPoints[criticalPoints.size()-1]-criticalPoints[criticalPoints.size()-2]);
                }
            }
            prev = temp;
            temp = temp->next;i++;
        }
        if(criticalPoints.size() < 2) return {-1, -1};
        
        return {mn, criticalPoints[criticalPoints.size()-1]-criticalPoints[0]};
    }
};