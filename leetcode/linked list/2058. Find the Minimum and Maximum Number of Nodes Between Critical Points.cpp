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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>store;
        ListNode* temp=head;
        int dist=1;
        int a=0;
        while(temp!=NULL)
        {
           
           if(a!=0)
           {
             if(temp->next!=NULL && ((temp->val>a && temp->val>temp->next->val) || (temp->val<a && temp->val<temp->next->val)))
             {
                store.push_back(dist);
                
             }
           }
           a=temp->val;
           temp=temp->next;
           dist++;
        }
        vector<int>ans;
        if(store.empty() || store.size()==1)
        {
             ans.push_back(-1);
             ans.push_back(-1);
             return ans;
        }
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=1;i<store.size();i++)
        {
          mini=min(mini,store[i]-store[i-1]);
        }
        maxi=store[store.size()-1]-store[0];
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
