class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    bool solve(Node* root)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        bool left=solve(root->left);
        bool right=solve(root->right);
        int a,b;
        
        if(root->left)
        {
            a=root->left->data;
        }
        else
        {
            a=0;
        }
        if(root->right)
        {
            b=root->right->data;
        }
        else
        {
            b=0;
        }
        bool check=root->data==a+b;
        return left && right && check;
        
    }
    
    
    int isSumProperty(Node *root)
    {
     // Add your code here
       if(solve(root))
       {
           return true;
       }
       return false;
    }
};
