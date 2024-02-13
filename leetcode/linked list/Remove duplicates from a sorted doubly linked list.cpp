class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp1=head;
        Node* temp2=head;
        while(temp2!=NULL)
        {
            while(temp2!=NULL && temp1->data==temp2->data)
            {
                temp2=temp2->next;
            }
            
            if(temp2!=NULL)
            {
                temp1->next=temp2;
                temp2->prev=temp1;
                temp1=temp1->next;
            }
            
            
        }
        if(temp2==NULL)
        {
            temp1->next=NULL;
        }
        return head;
        
    }
};
