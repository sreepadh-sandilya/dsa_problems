class Solution{
public:	
    
   void solve(int &n,vector<string>&ans,string &s,int count1,int count2)
   {
       if(s.length()==n)
       {
           ans.push_back(s);
           return;
       }
       
       s+='1';
       solve(n,ans,s,count1+1,count2);
       s.pop_back();
       if(count1>count2)
       {
           s+='0';
           solve(n,ans,s,count1,count2+1);
           s.pop_back();
       }
       
       
       
       
       
       
   }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    string s="";
	    int count1=0,count2=0;
	    solve(n,ans,s,count1,count2);
	    return ans;
	}
};
