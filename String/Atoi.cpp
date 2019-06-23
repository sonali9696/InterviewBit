int Solution::atoi(const string &A) {
    
    int i=0, l = A.size();
    while(A[i] == ' ' && i<l) 
    {
        i++;
    }
    
    if(i == l) return 0;
    
    if(!isdigit(A[i]) && A[i] != '-' && A[i] != '+') return 0;
        
    int sign = 1;
    if(A[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(A[i] == '+')
    {
        sign = 1;
        i++;
    }
    
    int num = 0;
    while(i<l && isdigit(A[i]))
    {
        if(num >= (INT_MAX - (A[i]-'0') )/10)
        {
            if(sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        
        num = num * 10 + (A[i]-'0');
        
        i++;
    }
    
    return sign*num;
    
}
