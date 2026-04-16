/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int helper(ListNode * curr){
    int cnt=0;
    while(curr!=NULL){
        curr=curr->next;
        cnt++;
    }
    return cnt;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1= helper(headA);
        int len2= helper(headB);
        int diff =abs(len1-len2);
        if (len1>len2){
            while(diff){
                headA=headA->next;
                diff--;
            }
            

        }
        else {
              while(diff){
                headB=headB->next;
                diff--;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if (headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
        
    }
};