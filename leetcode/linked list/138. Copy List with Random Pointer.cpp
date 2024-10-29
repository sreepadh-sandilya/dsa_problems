/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL){
            
            Node* node=new Node(temp->val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            // cout<<temp->random<<endl;
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else
            {
                temp->next->random=temp->random->next;
            }
            
            temp=temp->next->next;
        }
        
        temp=head;
        Node* n=new Node(-1);
        Node* temp1=n;
        while(temp!=NULL)
        {
            temp1->next=temp->next;
            temp1=temp1->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }

        return n->next;
    }
};
