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
    map<int, map<int, multiset<int>>> mp; // col -> (row -> {values})
void helper(TreeNode * root, int level,int iter)
{
    if (root == NULL)
    {
        return; 
    }
    mp[iter][level].insert(root->val);
    helper(root->left,level+1,iter-1);
     helper(root->right,level+1,iter+1);


}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    
         helper(root,0,0);
        vector<vector<int>>v;
        for(auto & [iter,levels]:mp)
        {
            vector<int> t;
            for(auto & [level,values]: levels)
            {
                t.insert(t.end(),values.begin(),values.end());
            }
            v.push_back(t);
        }
        return v;
        
    }
};