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
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto node : lists) if (node) pq.push(node);
        ListNode * l1=NULL;
       while(!pq.empty()){
        ListNode * t= pq.top();
        l1=helper(l1,t);
        pq.pop();

       }
       return l1;
        
    }
};