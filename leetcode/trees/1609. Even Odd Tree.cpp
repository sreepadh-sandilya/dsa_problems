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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0)
        {
            return false;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            
           int n=q.size();
           int a=-1;
           for(int i=0;i<n;i++)
           {
             TreeNode* node=q.front();
             q.pop();
             if(node->left)
             {
                 q.push(node->left);
             }
             if(node->right)
             {
                 q.push(node->right);
             }
             if(a==-1)
             {
                 a=node->val;
                 if(flag)
                 {
                     if(a%2!=0)
                     {
                       return false;
                     }
                 }
                 else
                 {
                     if(a%2==0)
                     {
                         return false;
                     }

                 }
             }
             else
             {
                 if(!flag)
                 {
                     if(a%2==0)
                     {
                         return false;
                     }
                     if(node->val<=a || node->val%2==0)
                     {
                         return false;
                     }
                     a=node->val;

                 }
                 else
                 {
                    if(a%2!=0)
                     {
                         return false;
                     }
                     if(node->val>=a || node->val%2!=0)
                     {
                         return false;
                     }
                     a=node->val;
                 }
             }
            //  cout<<a<<endl;
           }
           flag=!flag;
        }

        return true;
    }
};
