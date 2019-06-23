int Solution::maxSpecialProduct(vector<int> &A) {

    const int len = A.size();
    
    if(len <= 2) return 0;
    
    long long int ans = 0;
    
    long long int ls[len];
    long long int rs[len];
    
    for(int i=0; i<len; i++)
    {
        ls[i] = 0;
        rs[i] = 0;
    }
    
    // APPROACH -2 : using stack
    
    vector<long long int> ls_num_stack;
    vector<long long int> ls_ind_stack;
    int ls_top = -1;
    vector<long long int> rs_num_stack;
    vector<long long int> rs_ind_stack;
    int rs_top = -1;
    
    ls_num_stack.push_back(A[0]);
    ls_ind_stack.push_back(0);
    ls_top = 0;
    
    rs_num_stack.push_back(A[len-1]);
    rs_ind_stack.push_back(len-1);
    rs_top = 0;
    
    //Calculating left spcl value
    for(int i=1; i<len-1; i++)
    {
        while(ls_top >= 0 && A[i] >= ls_num_stack[ls_top]) 
        {
            ls_num_stack.pop_back();
            ls_ind_stack.pop_back();
            ls_top--;
        }
        
        if(ls_top >= 0) ls[i] = ls_ind_stack[ls_top];
        
        ls_num_stack.push_back(A[i]);
        ls_ind_stack.push_back(i);
        ls_top++;
    }
        
    //Calculating right spcl value
    for(int i=len-2; i>=0; i--)
    {
        while(rs_top >= 0 && A[i] >= rs_num_stack[rs_top]) 
        {
            rs_num_stack.pop_back();
            rs_ind_stack.pop_back();
            rs_top--;
        }
        
        if(rs_top >= 0) rs[i] = rs_ind_stack[rs_top];
        
        rs_num_stack.push_back(A[i]);
        rs_ind_stack.push_back(i);
        rs_top++;
    } 
        
   for(int i=0; i<len; i++)
   {
       long long int prod = ls[i]*rs[i];
       if(prod > ans) ans = prod;
   }
    
    
    /* APPROACH 1 : Brute force
    
    for(int i = 1; i < len-1; i++)
    {
        ls = 0, rs = 0;
        j = i-1;
        while(j >= 0)
        {
            if(A[j] > A[i]) 
            {
                ls = j;
                break;
            }
            j--;
        }
        j = i+1;
        while(j < len)
        {
            if(A[j] > A[i]) 
            {
                rs = j;
                break;
            }
            j++;
        }
        
        prod = ls*rs;
        
        if(ans < prod) ans = prod;
    }*/
    
    return (int) (ans % 1000000007);
    
     
    
}
