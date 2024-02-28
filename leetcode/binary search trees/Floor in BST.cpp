class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        Node* temp=root;
        int a=-1;
        while(temp!=NULL)
        {
            if(temp->data>x)
            {
                temp=temp->left;
            }
            else if(temp->data<x)
            {
                a=max(a,temp->data);
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
};
