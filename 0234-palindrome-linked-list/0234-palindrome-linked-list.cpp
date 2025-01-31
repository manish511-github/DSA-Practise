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
ListNode * helper(ListNode * head)
{
    ListNode * fast =head->next;
    ListNode * slow =head;
    while(fast!=NULL && fast->next !=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

    }
    return slow;

}
ListNode * helper2(ListNode * head)
{
   ListNode * curr =head;
   ListNode * prev=NULL;
   ListNode * cnext;
   while(curr!=NULL)
   {
    cnext = curr->next;
    curr->next=prev;
    prev=curr;
    curr= cnext;

   }
   return prev;


}

    bool isPalindrome(ListNode* head) {
        ListNode * mid =helper(head);
        ListNode * right =mid->next;
        mid->next=NULL;
        ListNode * curr =helper2(right);
        while(head!=NULL && curr!=NULL)
        {
            if(head->val!=curr->val)
            {
                
                return false;
            }
            head=head->next;
            curr=curr->next;

        }
        return true;

        
        
    }
};