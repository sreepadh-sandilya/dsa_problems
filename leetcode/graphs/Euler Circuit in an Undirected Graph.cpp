class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    vector<int>d(v,0);
	    for(int i=0;i<v;i++)
	    {
	        for(auto j:adj[i])
	        {
	            d[j]++;
	        }
	    }
	    for(auto i:d)
	    {
	        if(i%2==1)
	        {
	            return false;
	        }
	    }
	    return true;
	}

};
