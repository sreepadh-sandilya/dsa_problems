class Solution {
  public:
    void convert(Node *head, TreeNode *&root) {
        if(head==NULL)
        {
            return;
        }
        vector<TreeNode*>v;
        Node* temp=head;
        
        while(temp!=NULL)
        {
            TreeNode* node=new TreeNode(temp->data);
            v.push_back(node);
            temp=temp->next;
        }
        int n=v.size();
        root=v[0];
        for(int i=0;i<n;i++)
        {
            if(2*i+1<n)
            {
                v[i]->left=v[2*i+1];
            }
            if(2*i+2<n)
            {
                v[i]->right=v[2*i+2];
            }
        }
    }
};
