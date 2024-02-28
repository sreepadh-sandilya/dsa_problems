int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    Node* temp=root;
    int a=INT_MAX;
    while(temp!=NULL)
    {
        if(temp->data>input)
        {
            a=min(a,temp->data);
            temp=temp->left;
        }
        else if(temp->data<input)
        {
            temp=temp->right;
        }
        else
        {
            return temp->data;
        }
    }
    if(a==INT_MAX)
    {
        return -1;
    }
    return a;
}
