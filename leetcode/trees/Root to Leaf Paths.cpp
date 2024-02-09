void solve(Node* root,vector<vector<int>>&ans,vector<int>&v)
 {
     if(root==NULL)
     {
         return;
     }
     if(root->left==NULL && root->right==NULL)
     {
         v.push_back(root->data);
         ans.push_back(v);
         v.pop_back();
         return;
     }
     v.push_back(root->data);
     solve(root->left,ans,v);
    //  v.pop_back();
     
     solve(root->right,ans,v);
     v.pop_back();
 }
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>>ans;
    vector<int>v;
    if(root==NULL)
    {
        return ans;
    }
    
    
    solve(root,ans,v);
    return ans;
    
}
