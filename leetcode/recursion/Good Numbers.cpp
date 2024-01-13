bool goodWithoutDigit(int n, int digit,int sum,int p) {
    if(n==0)
	{
		return true;

	}
	if (n % 10 == digit || (sum>=n%10 && to_string(n).length()!=p))
	    
        return false;
    // cout<<sum<<endl;
    if(goodWithoutDigit(n/10,digit,sum+n%10,p)==false)
	{
		return false;
	}
	return true;
    
}

vector<int> goodNumbers(int a, int b, int digit) {
    vector<int> ans;

    for (int i = a; i <= b; i++) {
                string s = to_string(i);
                if (goodWithoutDigit(i, digit, 0, s.length()))
                  ans.push_back(i);
    }
	return ans;
}
