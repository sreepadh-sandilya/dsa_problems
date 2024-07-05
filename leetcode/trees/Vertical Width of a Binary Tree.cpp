class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        // code here
        if(root==NULL)
        {
            return 0;
        }
        int r=INT_MIN,l=INT_MAX;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty())
        {
            int d=q.front().first;
            Node* node=q.front().second;
            q.pop();
            r=max(r,d);
            l=min(l,d);
            if(node->left)
            {
                q.push({d-1,node->left});
            }
            if(node->right)
            {
                q.push({d+1,node->right});
            }
        }
        return r-l+1;
    }
};
