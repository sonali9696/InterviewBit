vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {

    vector <int> ans;
    
    int p = 0, q = 0;
    int len1 = A.size(), len2 = B.size();
    
    if(len1 > len2)
    {
        for(q = 0; q < len2; q++)
        {
            while(p < len1 && A[p] < B[q]) 
            {
                p++;
            }
            
            if(p == len1) break;
            else if(A[p] ==  B[q]) 
            {
                ans.push_back(A[p]);
                p++; //not to be used again for comparison
                continue;
            }
            else continue;
        }
    }
    else
    {
        for(p = 0; p < len1; p++)
        {
            while(q < len2 && B[q] < A[p]) q++;
            
            if(q == len2) break;
            else if(A[p] ==  B[q]) 
            {
                ans.push_back(A[p]);
                q++;
                continue;
            }
            else continue;
            
        }
    }
    
    
    return ans;
}
