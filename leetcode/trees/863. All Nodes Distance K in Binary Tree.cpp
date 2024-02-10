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
    void find(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL || root==target)
        {
            return;
        }

        if(root->left)
        {
            mp[root->left]=root;
        }
        if(root->right)
        {
            mp[root->right]=root;
        }
        find(root->left,target,mp);
        find(root->right,target,mp);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>mp;
        find(root,target,mp);
        queue<TreeNode*>q;
        q.push(target);
        vector<int>ans;
        for(auto i:mp)
        {
            cout<<i.first->val<<" "<<i.second->val<<endl;
        }
        unordered_map<TreeNode*,int>vis;
        // vis[target]=1;
        while(!q.empty())
        {
            if(k<0)
            {
                break;
            }
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* node=q.front();
                cout<<node->val<<endl;
                q.pop();
                vis[node]=1;
                if(k==0)
                {
                    ans.push_back(node->val);

                }
                // q.pop();
                if(node->left && vis.count(node->left)==0)
                {
                    q.push(node->left);
                    // vis[node->left]=1;

                }
                if(node->right && vis.count(node->right)==0)
                {
                    q.push(node->right);
                    // vis[node->right]=1;
                }
                if(mp.count(node) && vis.count(mp[node])==0)
                {
                    q.push(mp[node]);
                    // vis[node]=1;
                }
            }
            k--;



        }

        return ans;
        
    }
};
