class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root==NULL){
            return root;
        }
        root->left=RemoveHalfNodes(root->left);
        root->right=RemoveHalfNodes(root->right);
        if(root->left && !root->right)
        {
            return root->left;
        }
        else if(!root->left && root->right)
        {
            return root->right;
        }
        else
        {
            return root;
        }
        
    }
};
