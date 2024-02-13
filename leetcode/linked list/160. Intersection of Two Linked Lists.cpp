/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int sum1=0,sum2=0;
        while(temp1!=NULL)
        {
            temp1=temp1->next;
            sum1++;
        }
        while(temp2!=NULL)
        {
            temp2=temp2->next;
            sum2++;
        }
        temp1=headA;
        temp2=headB;
        if(sum1>sum2)
        {
            int k=sum1-sum2;
            while(k--)
            {
                temp1=temp1->next;
            }
        }
        else
        {
            int k=sum2-sum1;
            while(k--)
            {
                temp2=temp2->next;
            }
        }

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};
