vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int>ans;
    if((num & (1<<i-1)) > 0)
    {
        ans.push_back(1);
    }
    else{
        ans.push_back(0);
    }
    ans.push_back(num | (1<<i-1));
    ans.push_back(num & ~(1<<i-1));
    return ans;
}
