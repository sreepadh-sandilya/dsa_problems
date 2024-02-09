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
    int maxi=INT_MIN;
    int sum(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int l=sum(root->left);
        int r=sum(root->right);
        maxi=max({maxi,r+l+root->val,l+root->val,r+root->val,root->val});
        return max({l+root->val,r+root->val,root->val});
        
    }
    int maxPathSum(TreeNode* root)
    {
        sum(root);
        return maxi;
    }
};
