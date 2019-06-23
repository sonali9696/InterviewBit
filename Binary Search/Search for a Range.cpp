vector<int> Solution::searchRange(const vector<int> &A, int B) {

    vector <int> ans;
    ans.push_back(0);
    ans.push_back(0);
    
    
    int n = A.size();
    
    int beg = 0, end = n-1,mid,flag=0;
    while(beg <= end)
    {
        mid = (beg+end)/2;
        if(A[mid] < B) beg = mid+1;
        else if(A[mid] > B) end = mid-1;
        else{
            flag = 1;
            break;
        } 
    }
    
    if(flag == 0)
    {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    else
    {
        int i=mid-1,j=mid+1;
        int start = mid, finish = mid;
        
        //binary search for starting pos
        while(start != 0 && flag == 1)
        {
            end = start-1;
            beg = 0;
            flag = 0;
            while(beg <= end)
            {   
                mid = (beg+end)/2;
                if(A[mid] < B) beg = mid+1;
                else if(A[mid] > B) end = mid-1;
                else{
                    flag = 1;
                    break;
                } 
            }
            if(flag == 0) break; //no more start pos
            else
            {
                start = mid;
            }
        }   
        
        flag = 1;
        //binary search for ending pos
        while(finish != n-1 && flag == 1)
        {
            end = n-1;
            beg = finish+1;
            flag = 0;
            while(beg <= end)
            {   
                mid = (beg+end)/2;
                if(A[mid] < B) beg = mid+1;
                else if(A[mid] > B) end = mid-1;
                else{
                    flag = 1;
                    break;
                } 
            }
            if(flag == 0) break; //no more end pos
            else
            {
                finish = mid;
            }
        }
        
        /*while(i>=0 && A[i] == A[mid]) {
            beg--;
            i--;
        }
        while(j<n && A[j] == A[mid]) {
            end++;
            j++;
        }*/
        
        ans[0] = start;
        ans[1] = finish;
        return ans;
    }
    

}
