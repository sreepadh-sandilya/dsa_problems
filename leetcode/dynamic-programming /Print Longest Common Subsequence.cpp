string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
               dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}

		}
	}

	int i=n,j=m;
	string s="";
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
           s=s1[i-1]+s;
		   i--;
		   j--;
		}
		else{
			if(dp[i][j-1]>dp[i-1][j])
			{
				j--;
			}
			else{
				i--;
			}
		}
	}
	// cout<<s<<endl;
	return s;
}
