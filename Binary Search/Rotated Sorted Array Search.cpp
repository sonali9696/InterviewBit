int binarySearch(const vector<int> &A, int B, int beg, int end)
{
    int mid;
    while(beg <= end)
    {
        mid = (beg+end)/2;
        if(A[mid] == B) return mid;
        if(A[mid] > B) end = mid-1;
        else beg = mid+1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int beg=0, end=n-1,mid,flag=0;
    
    while(beg <= end)
    {
        mid = (beg+end)/2;
        
        if(A[mid] == B)
        {
            return mid;
        }
        
        if(A[mid] > A[mid+1] || A[mid-1] > A[mid])//mid=pivot or mid-1=pivot (pivot found!)
        {
            int ans1 = binarySearch(A,B,0,mid-1);//left
            int ans2 = binarySearch(A,B,mid+1,n-1);//right
            if(ans1 == -1 && ans2 == -1) return -1;
            else if(ans1 == -1) return ans2;
            else return ans1;
        }
        else //find pivot
        {
            
            if(A[mid] > A[end]) beg = mid+1;
            else if(A[mid] < A[end]) end = mid;
            else if(A[mid] == A[end] || A[beg] == A[mid])//duplicates
            {
                for(int i=0; i<end;i++)
                {
                    if(A[i] == B)
                        return i;
                }
                return -1;
            }
        }
    }
    return -1;
}
