int Solution::findMinXor(vector<int> &A) {
    
    int len = A.size();
    int min = INT_MAX;
    
    //M-1: brute force
    /*for(int i = 0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            int temp = A[i] ^ A[j];
            if( temp < min ) min = temp;
            cout<<A[i]<<" ^ "<<A[j]<<" = "<<temp<<endl;
        }
    }
    
    return min;*/
    
    
    //M-2: sorting then comparing only consecutive numbers
    
    sort(A.begin(), A.end());
    for(int i = 0; i < len-1; i++)
    {
        int temp = A[i] ^ A[i+1];
        if(temp < min) min = temp;
    }
    return min;
}
