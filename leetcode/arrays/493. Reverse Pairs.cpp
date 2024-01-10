class Solution {
public:
    void merge(vector<int>& nums,int s,int m,int e,int &ans)
    {
        int len1=m-s+1;
        int len2=e-m;
        int main=s;
        int* first=new int[len1];
        int* second=new int[len2];
        for(int i=0;i<len1;i++)
        {
            first[i]=nums[main++];
        }
        for(int i=0;i<len2;i++)
        {
            second[i]=nums[main++];
        }
        main=s;
        int ind1=0,ind2=0;
        while(ind1<len1 && ind2<len2)
        {
            if(first[ind1]>second[ind2])
            {
                nums[main++]=second[ind2++];
            }
            else
            {
                nums[main++]=first[ind1++];
            }
        }
        while(ind1<len1)
        {
            nums[main++]=first[ind1++];
        }
        while(ind2<len2)
        {
            nums[main++]=second[ind2++];
        }

    }
    int count(vector<int>& nums,int s,int m,int e,int &ans)
    {
        int right=m+1,cnt=0;
        for(int i=s;i<=m;i++)
        {
            while(right<=e && nums[i]>2*(long long)nums[right])
            {
                right++;
            }
            cnt+=right-m-1;
        }
        return cnt;
    }
    int mergesort(vector<int>& nums,int s,int e,int &ans)
    {
        int cnt=0;
        if(s>=e)
        {
            return cnt;
        }
        int m=(s+e)/2;
        cnt+=mergesort(nums,s,m,ans);
        cnt+=mergesort(nums,m+1,e,ans);
        cnt+=count(nums,s,m,e,ans);
        merge(nums,s,m,e,ans);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        ans=mergesort(nums,0,n-1,ans);
        return ans;
        
    }
};
