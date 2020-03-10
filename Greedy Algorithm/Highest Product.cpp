int Solution::maxp3(vector<int> &A) {
    int l = A.size();
    if(l < 3) return 0;
    if(l == 3) return A[0]*A[1]*A[2];
    
    sort(A.begin(), A.end());
    
    
    // -, - , +
    // +, +, +
    // no 0
    //-, -, - if no +
    
    if (A[0] > 0 || A[1] > 0) //all positive numbers or 0 then positive
        return A[l-1] * A[l-2] * A[l-3];
    else if (A[l-1] < 0) //all -ve numbers
        return A[l-1] * A[l-2] * A[l-3];
    else if (A[0] < 0) //contains -ve numbers
    {
        long long int prod1 = 1; //+ve numbers
        int count = 0, ind = l-1;
        long long int max = INT_MIN;
        while(count != 3)
        {
            if(A[ind] == 0) 
            {
                ind--;
                continue;
            }
            else
            {
                prod1 *= A[ind];
                ind--;
                count++;
            }
        }
        
        //cout<<"p1="<<prod1<<endl;
        if(prod1 > max) max = prod1;
        
        long long prod2 = INT_MIN;
        //-,-,+
        if(A[0] < 0 && A[1] < 0) 
            prod2 = A[0] * A[1] * A[l-1];
        if(prod2 > max) max = prod2;
        
        //cout<<"p2="<<prod2<<endl;
        
        long long int prod3 = INT_MIN; //if there is no zero then negative number is highest
        //-,-,- 
        if(A[l-3] < 0)
        {
            if(A[l-1] < 0) prod3 = A[l-1] * A[l-2] * A[l-3];
            else if(l >= 5) prod3 = A[l-3] * A[l-4] * A[l-5];
        }
        if(prod3 > max) max = prod3;
        //cout<<"p3="<<prod3<<endl;
        
        long long int prod4 = 0;
        if(prod4 > max) max = prod4;
        
        return max;
    }
    
}
