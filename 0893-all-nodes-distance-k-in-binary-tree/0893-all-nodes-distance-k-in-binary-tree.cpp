/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

unordered_map<TreeNode*,TreeNode *> mp;
void helper1(TreeNode *root,TreeNode * parent)
{
    if (root==NULL)
    {
        return;
    }
    mp[root]=parent;

    helper1(root->left,root);
    helper1(root->right,root);


}

void helper(TreeNode * root , int k,unordered_map<TreeNode*,int> &vis,vector<int> & v)
{
    if (root==NULL)
    {
        return ;
    }
    if (vis.find(root)!=vis.end())
    {
        return;
    }
    vis[root]=1;

    if (k==0)
    {
        
        v.push_back(root->val);
    }
    helper(mp[root],k-1,vis,v);
    helper(root->left,k-1,vis,v);
    helper(root->right,k-1,vis,v);
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //sabke parent nikalo
        helper1(root,NULL);
        vector<int> v;
        unordered_map<TreeNode *,int> vis;
        
        helper(target,k,vis,v);
        return v;



        
    }
};