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
    // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
    // }
    TreeNode* solve(vector<int>& pos, vector<int>& in,unordered_map<int,int>&mp,int ins,int ine,int poss,int pose)
    {
        if(poss>pose)
        {
            return NULL;
        }
        
        TreeNode* root=new TreeNode(pos[pose]);
        int elem=mp[pos[pose]];
        int nelem=elem-ins;
        root->left=solve(pos,in,mp,ins,elem-1,poss,poss+nelem-1);
        root->right=solve(pos,in,mp,elem+1,ine,poss+nelem,pose-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        unordered_map<int,int>mp;
        int n=pos.size();
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        // reverse(pre.begin(),pre.end());
        return solve(pos,in,mp,0,n-1,0,n-1);

        
    }
};
