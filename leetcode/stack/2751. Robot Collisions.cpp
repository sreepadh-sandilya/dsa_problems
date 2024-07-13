class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
       vector<pair<int,int>>pos;
       int n=positions.size();
       for(int i=0;i<n;i++){
        pos.push_back({positions[i],i});
       }
       sort(pos.begin(),pos.end());
       stack<pair<int,int>>st;
       for(auto i:pos){
        if(st.empty() || directions[i.second]=='R')
        {
            st.push(i);
            continue;
        }
        
            pair<int,int>r=i;
            int y=0;
            while(!st.empty() && directions[st.top().second] != directions[r.second]){
                if(health[r.second]>health[st.top().second]){
                    health[st.top().second]=0;
                    st.pop();
                    health[r.second]--;
                }
                else if(health[r.second]==health[st.top().second]){
                    health[r.second]=0;
                    health[st.top().second]=0;
                    st.pop();
                    y=1;
                    break;
                }
                else{
                    health[st.top().second]--;
                    health[r.second]=0;
                    y=1;
                    break;
                }
            }
            if(y==0){
                st.push(r);
            }
        
       }
       vector<int>ans;
       for(auto i:health)
       {
        if(i!=0)
        {
            ans.push_back(i);
        }
       }
       return ans;
       
    }
};
