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
int helper(TreeNode * root,int &maxi)
{
    if (root ==NULL)
    {
        return -1001;
    }
    int leftval= helper(root-> left,maxi);
    int rightval= helper(root->right,maxi);
    maxi =max(maxi,max(root->val+leftval+rightval,root->val+max(leftval,rightval)));
    maxi=max(maxi,root->val);
    return max(root->val,root->val+max(leftval,rightval));
}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        if(root->left==NULL && root->right ==NULL)
        {
            return root->val;
        }
     helper(root,maxi);
     return maxi;

        
    }
};