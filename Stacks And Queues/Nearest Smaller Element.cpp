vector<int> Solution::prevSmaller(vector<int> &A) {
    //if A[i]>top then push A[i]
    //if < top then replace top with A[i];
    //if = top then pop top, compare with next element then push A[i] according to new case
    
    stack<int> st;
    
    int l = A.size();
    vector<int> ans;
    ans.push_back(-1);
    st.push(A[0]);
    
    for(int i=1; i<l; i++)
    {
        if(A[i] == st.top()) 
        {
            st.pop();//it will push itself at end of this iteration
            if(st.empty())
            {
                ans.push_back(-1);
                st.push(A[i]);
                continue;
            }
        }
        
        if(A[i] > st.top())
        {
            ans.push_back(st.top());
            st.push(A[i]);
        }
        else if(A[i] < st.top())
        {
            while(!st.empty() && A[i] <= st.top())
            {
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top()); 
            
            st.push(A[i]);
        }
        
    }
    return ans;
}
