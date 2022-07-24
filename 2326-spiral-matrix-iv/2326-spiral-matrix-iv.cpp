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
        void storeData(int sx, int ex, int sy, int ey, ListNode *head, vector<vector<int>> &mat){
        if(sx>ex or sy>ey) return;
        int i = sx, j=sy;
        while(j<=ey){
            mat[i][j] = head->val;
            head = head->next;
            if(head == NULL) return;
            j++;
        }
        j--;i++;
        while(i<=ex){
            mat[i][j] = head->val;
            head = head->next;
            if(head == NULL) return;
            i++;
        }
        i--;j--;
        while(j>=sy){
            mat[i][j] = head->val;
            head = head->next;
            if(head == NULL) return;
            j--;
        }
        j++;i--;
        while(i>sx){
            mat[i][j] = head->val;
            head = head->next;
            if(head == NULL) return;
            i--;
        }
        storeData(sx+1,ex-1, sy+1, ey-1, head, mat);
    }
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        storeData(0, m-1, 0, n-1, head, ans);
        return ans;
    }
};