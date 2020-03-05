int Solution::majorityElement(const vector<int> &A) {
    
    map<int, int> m; //element, freq
    int l = A.size();
    if(l == 0) return 0;
    
    int goal = floor(l/2);
    
    for(int i = 0; i < l; i++)
    {
        if(m.find(A[i])!= m.end()) //exists
        {
            m[A[i]] = m[A[i]] + 1;
        }
        else //does not exist - new entry
        {
            m[A[i]] = 1;
        }
        
        if(m[A[i]] > goal) return A[i];
    }
    
    return A[l-1]; //nothing was a majority - behaviour of this case not defined
    
    
}
