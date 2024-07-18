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
    vector<int> solve(TreeNode* root, int distance,int &ans){
        if(root==NULL){
            return {0};
        }
        if(root->left==NULL && root->right==NULL){
            return {1};
        }
        vector<int>left=solve(root->left,distance,ans);
        vector<int>right=solve(root->right,distance,ans);
        for(auto i:left){
            for(auto j:right){
                if(i>0 && j>0 && i+j<=distance){
                    ans++;
                }
            }
        }
        vector<int>res;
        for(auto i:left){
            if(i>0 && i<distance){
                res.push_back(i+1);
            }
        }
        for(auto i:right){
            if(i>0 && i<distance){
                res.push_back(i+1);
            }
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        solve(root,distance,ans);
        return ans;
    }
};
