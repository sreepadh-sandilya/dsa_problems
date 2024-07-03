class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node* dummy= new Node(-1);
        Node* temp1=head;
        Node* temp2=dummy;
        Node* h=dummy;
        int a=0;
        while(temp1!=NULL)
        {
            if(a!=temp1->data)
            {
                if(temp1->next!=NULL)
                {
                    if(temp1->data!=temp1->next->data)
                    {
                        Node* node=new Node(temp1->data);
                        temp2->next=node;
                        temp2=temp2->next;
                    }
                }
                else
                {
                    Node* node=new Node(temp1->data);
                    temp2->next=node;
                    temp2=temp2->next;
                }
            }
            a=temp1->data;
            temp1=temp1->next;
        }
        return h->next;
        
    }
};
