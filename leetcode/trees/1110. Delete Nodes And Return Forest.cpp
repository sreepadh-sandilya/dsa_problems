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
    void post(TreeNode* &root,vector<TreeNode*>&ans,unordered_map<int,int>&mp){
        if(root==NULL){
            return;
        }
        post(root->left,ans,mp);
        post(root->right,ans,mp);
        if(mp[root->val]==1){
            
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            root=NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<int,int>mp;
        for(auto i:to_delete){
            mp[i]=1;
        }
        post(root,ans,mp);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};
