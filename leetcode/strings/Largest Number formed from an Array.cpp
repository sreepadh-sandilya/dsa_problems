class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool comp(string a,string b)
	{
	    string s1=a+b;
	    string s2=b+a;
	    return s1>s2;
	}
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    sort(arr.begin(),arr.end(),comp);
	    string s="";
	    for(auto i:arr)
	    {
	        s+=i;
	    }
	    return s;
	}
};
