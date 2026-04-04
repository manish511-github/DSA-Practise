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
    ListNode* helper(ListNode* l1,ListNode* l2){
        ListNode * curr= new ListNode (-1);
        ListNode* dummy =curr;
        while(l1!=NULL && l2!=NULL){
            if (l1->val<l2->val){
                curr->next=l1;
                l1=l1->next;
                curr=curr->next;
            }
            else {
                curr->next=l2;
                l2=l2->next;
                curr=curr->next;
            }
        }
        if (l1!=NULL){
            curr->next=l1;
        }
        if (l2!=NULL){
            curr->next=l2;
        }
        return dummy->next;
    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // 1 4 5 
        // 1 3 4
        // 2 6 
        
        // 1 2 4 5 6        // 1 3 4
        int i=0;

        int n=lists.size();
        if (n==0){
            return NULL;
        }
        int j=n-1;
        int last =j;
        while(last!=0){
            i=0;
            
             while(i<j){
            lists[i]=helper(lists[i],lists[j]);
            i++;
            j--;
            if (i>=j){
                last=j;
            }
        }
        }
        return lists[0];
       
    }
};