class Solution{
    public:
    int firstElementKTime(int n, int k, int arr[])
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>=k)
            {
                return arr[i];
            }
        }
        return -1;
    }
};
