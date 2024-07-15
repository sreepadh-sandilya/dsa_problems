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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map<int,vector<pair<int,int>>>mp;
        unordered_map<int,int>find;
        for(auto i:desc){
            mp[i[0]].push_back({i[1],i[2]});
            find[i[1]]=1;
        }
        TreeNode* root;
        for(auto i:desc){
            if(find[i[0]]==0){
                root=new TreeNode(i[0]);
                break;
            }
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            for(auto i:mp[node->val]){
                if(i.second==1)
                {
                    node->left=new TreeNode(i.first);
                    q.push(node->left);
                }
                else{
                    node->right=new TreeNode(i.first);
                    q.push(node->right);
                }
            }

        }
        return root;

    }
};
