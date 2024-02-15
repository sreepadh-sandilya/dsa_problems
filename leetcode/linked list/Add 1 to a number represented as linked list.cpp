class Solution
{
    public:
    Node* solve(Node* &root,int &c)
    {
        if(root==NULL)
        {
            return root;
        }
        solve(root->next,c);
        int d=(c+root->data)/10;
        root->data=(c+root->data)%10;
        c=d;
        
        return root;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int c=1;
         solve(head,c);
        if(c==0)
        {
            return head;
        }
        Node* t=new Node(c);
        t->next=head;
        head=t;
        return head;
    }
};
