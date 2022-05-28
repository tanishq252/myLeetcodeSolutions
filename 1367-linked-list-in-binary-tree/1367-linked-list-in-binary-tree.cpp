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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPath = false;
    vector<int> subPath;
    
    void pathFinder(TreeNode *root, vector<int> &path, int pathLen){
        if(root==NULL) return;
        path[pathLen] = root->val;
        pathLen++;
        if(root->left==NULL and root->right==NULL){
            if(pathLen<subPath.size()) return;
            if(pathLen == subPath.size()){
                vector<int> temp(path.begin(), path.begin()+pathLen);
                if(temp == subPath){hasPath = true; return;}
            }
            else{
                for(int i=0;i<pathLen-subPath.size()+1;i++){
                    vector<int> temp(path.begin()+i,path.begin()+i+subPath.size());
                    if(temp == subPath){
                        hasPath=true;
                        return;
                    }
                }
            }
        }else{
            pathFinder(root->left, path, pathLen);            
            pathFinder(root->right, path, pathLen);
        }
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> path(2500);
        ListNode *temp = head;
        while(temp!=NULL){
            subPath.push_back(temp->val);
            temp = temp->next;
        }
        pathFinder(root, path, 0);
        return hasPath;
    }
};