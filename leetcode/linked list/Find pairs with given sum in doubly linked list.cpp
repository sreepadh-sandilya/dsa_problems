class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        Node* temp=head;
        vector<pair<int,int>>ans;
        while(temp!=tail)
        {
            if(temp->data+tail->data==target)
            {
                ans.push_back({temp->data,tail->data});
                temp=temp->next;
                // tail=tail->prev;
            }
            else if(temp->data+tail->data>target)
            {
                tail=tail->prev;
            }
            else
            {
                temp=temp->next;
            }
        }
        return ans;
    }
};
