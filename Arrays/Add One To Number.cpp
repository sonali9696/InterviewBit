vector<int> Solution::plusOne(vector<int> &A) {
    int len1 = A.size(), flag = 0, j = len1 - 1, isModified = 0;
    vector <int> C;
    
    if(len1 == 0) return A;
    
    //remove leading zeros from output
    if(A[0] == 0)
    {
        int k = 0, flag2 = 0, count=0;
        while(A[k] == 0 and k<len1)
        {
            if(A[k] == 0) count++;
            k++;
        }
        if(count == len1)
        {
            C.push_back(1);
            return C;
        }
        else
        {
            for(int i = count; i<len1; i++)
            {
                C.push_back(A[i]);
            }
            isModified = 1;
        }
        
        if(isModified = 1) A = C;
    }
    
    len1 = A.size();
    
    if(A[len1-1] < 9)
    {
        A[len1-1] = A[len1-1] + 1;
        return A;
    }
    else while(A[j] == 9)
    {
        A[j] = 0;
        j--;
        if(j == -1)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1)
    {
        const int len2 = len1+1;
        vector <int> B;
        B.push_back(1);
        for(int i=1; i<len2; i++) B.push_back(0);
        return B;
    }
    else
    {
        A[j] = A[j] + 1;
        return A;
    }
    //handle 999
    
}
