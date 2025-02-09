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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                queue<TreeNode*> q;
            vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
            
        }
        bool i=true;
        
        q.push(root);
        while(!q.empty())
        {
           
            vector<int> v;
            
            int w=q.size();
            
            while(w--)
            {
            TreeNode * curr=q.front();
                q.pop();
                v.push_back(curr->val);
                
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                    
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                    
                }
            }
 if(i==1)
            {
                            ans.push_back(v);
            }
            else 
            {
                reverse(v.begin(),v.end());
                 ans.push_back(v);
                
            }
i=!i;
            
            

            v.clear();
            
        }
        return ans;
    }
};