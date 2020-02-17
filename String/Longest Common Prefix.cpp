string Solution::longestCommonPrefix(vector<string> &A) {
    
    int n = A.size(); //number of strings
    int smallLen = INT_MAX; //smallestStringLength
    
    for(int i=0; i<n; i++)
    {
        int len = A[i].length();
        if(len < smallLen) smallLen = len;
    }
    
    string ans = "";
    
    if(smallLen == INT_MAX) return ans;
    
    for(int i=0; i<smallLen; i++)
    {
        char temp = A[0][i];
        int flag = 0;
        for(int j=1; j<n; j++)
        {
            if(A[j][i] != temp)
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1) break;
        else ans = ans + temp;
    }
    
    return ans;
}
