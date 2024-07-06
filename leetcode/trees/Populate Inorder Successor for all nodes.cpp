class Solution {
  public:
    Node* prev=NULL;
    void reversein(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        reversein(root->right);
        root->next=prev;
        prev=root;
        reversein(root->left);
    }
    void populateNext(Node *root) {
        // code here
        reversein(root);
    }
};
