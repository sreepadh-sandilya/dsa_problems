class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(int i=0;i<num;i++)
        {
            pq.push(arr[i]);
            if(i>k)
            {
                ans.push_back(pq.top());
                pq.pop();
                
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
    
};
