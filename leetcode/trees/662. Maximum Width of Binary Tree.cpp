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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxi=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            unsigned long long s=q.size();
            unsigned long long l=0,r=0; 
            for(int i=0;i<s;i++)
            {              
                 
                pair<TreeNode*,int>temp=q.front();
                q.pop();
                TreeNode* node=temp.first;
                unsigned long long d=temp.second;
                
                if(i==0)
                {
                    l=d;
                }
                if(i==s-1)
                {
                    r=d;
                }
                // cout<<r<<" "<<l<<" "<<r-l+1<<endl;
                
                if(node->left)
                {
                    q.push({node->left,d*2+1});
                }
                if(node->right)
                {
                    q.push({node->right,d*2+2});
                }

            }
            maxi=max(maxi,r-l+1);

        }
        return maxi;

    }
};
