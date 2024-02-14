/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(ListNode* head, int n,int &sum)
    {
        if(head->next==NULL)
        {
            return;
        }
        solve(head->next,n,sum);
        sum++;
        if(sum==n)
        {
            head->next=head->next->next;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum=0;
        solve(head,n,sum);
        if(sum<n)
        {
            return head->next;
        }
        return head;
        
    }
};
