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
    ListNode* solve(ListNode* head)
    {
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* newh=solve(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newh;


        
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
        {
            return head;
        }
        return solve(head);

        
    }
};
