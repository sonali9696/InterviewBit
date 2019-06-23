int Solution::sqrt(int A) {
    
    if(A == 0) return 0;
    
    int beg,end;
    
    beg=1;end=A;
    
    //return 0;
   int mid,rhs;
   while(beg<=end)
    {
        mid = (beg+end)/2;
        rhs = A/mid;
        if(mid == rhs) break;
        else if(mid > rhs) end = mid-1;
        else if(mid < rhs) beg = mid+1;
        /*prod = mid*mid;
        if(prod == A) break;
        else if(prod > A) end = mid-1;
        else if(prod < A) beg = mid+1;*/
    }
    
    if(mid == rhs) return mid;
    else return end;//beg>end
}
