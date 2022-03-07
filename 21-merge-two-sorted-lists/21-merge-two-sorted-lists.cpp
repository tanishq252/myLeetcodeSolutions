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
    ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
        
//         recursion
        
        if(t1==NULL){return t2;}
        else if(t2 == NULL){return t1;}
        
        
        if(t1->val<t2->val){
            t1->next = mergeTwoLists(t1->next, t2);
            return t1;
        }
        else{
            t2->next = mergeTwoLists(t2->next, t1);
            return t2;
        }
        
        
        
//          USING BASIC LOOPS   
        
//         ListNode* newList = NULL;
//         if(t1==NULL){return t2;}
//         else if(t2 == NULL){return t1;}

//         if(t1->val<t2->val){
//             newList = t1;
//             t1 = t1->next;
//         }else{
//             newList = t2;
//             t2 = t2->next;
//         }
//         ListNode* temp = newList;
//         while(t1!=NULL && t2!=NULL){
//             if(t1->val < t2->val){
//                 temp->next = t1;
//                 t1 = t1->next;

//             }else{
//                 temp->next = t2;
//                 t2 = t2->next;
//                 cout<<"oo"<<"\n";
//             }
//             temp = temp->next;
//         }
        
//         if(t1){
//             temp->next = t1;
//         }else{
//             temp->next = t2;
//         }
//         return newList;
    }
};