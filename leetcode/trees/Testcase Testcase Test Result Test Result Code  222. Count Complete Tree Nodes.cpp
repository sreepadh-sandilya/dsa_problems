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
//    int sum=0;
    int findleft(TreeNode* root)
    {
        TreeNode* node=root;
        int sum=0;
        while(node!=NULL)
        {
            node=node->left;
            sum++;
        }
        return sum;
    }
    int findright(TreeNode* root)
    {
        TreeNode* node=root;
        int sum=0;
        while(node!=NULL)
        {
            node=node->right;
            sum++;
        }
        return sum;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int left=findleft(root);
        int right=findright(root);
        if(left==right)
        {
            return (1<<left)-1;
        }
        int l=countNodes(root->left);
        int r=countNodes(root->right);
        return l+r+1;

        

        
    }
};
