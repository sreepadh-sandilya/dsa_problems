int Solution::solve(vector<int> &A, int B) {
    map<int,int>mp;
    mp[0]++;
    int sum=0,cnt=0,n1=A.size();
    for(int i=0;i<n1;i++)
    {
        sum=(sum^A[i]);
        cnt+=mp[(sum^B)];      
        mp[sum]++;
    }
    return cnt;
}


