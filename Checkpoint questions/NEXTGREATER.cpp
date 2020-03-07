vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> s;
    vector<int> ans;
    
    int l = A.size();
    
    s.push(A[l-1]);
    ans.push_back(-1);
    
    for(int i = l-2; i >= 0; i--)
    {
        if(s.empty())
        {
            ans.push_back(-1);
            s.push(A[i]);
        }
        else if(A[i] >= s.top()) 
        {
            while(!s.empty() && s.top() <= A[i]) s.pop();
            
            if(!s.empty()) ans.push_back(s.top());
            else ans.push_back(-1);
            
            s.push(A[i]);
        }
        else if(A[i] < s.top())
        {
            ans.push_back(s.top());
            s.push(A[i]);
        }
    }
    
    //reverse vector ans
    reverse(ans.begin(), ans.end());
    
    return ans;
}
