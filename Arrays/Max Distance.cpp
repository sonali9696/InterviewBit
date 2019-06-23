int Solution::maximumGap(const vector<int> &A) {
    const int len = A.size();
    
    if(len == 0) return -1;
    else if(len == 1) return 0;
    else if(len == 2)
    {
        if(A[1] >= A[0]) return 1;
        else return 0; //as i and j can be equal
    }
    
    
    int index[len];
    int maxIndex[len];
    
    
    //sort array, while preserving index
    vector <pair<int,int> > vp;
    
    for(int i=0; i<len;i++) vp.push_back(make_pair(A[i],i));
    sort(vp.begin(),vp.end());
    
    for(int i=0; i<len;i++)
    {
        index[i] = vp[i].second;
    }
    
    //preprocess maxIndex s.t. maxIndex(i) = max of index array values from i till len-1
    maxIndex[len-1] = index[len-1];
    
    for(int i=len-2; i>=0; i--)
    {
        maxIndex[i] = max(maxIndex[i+1], index[i]);
    }
    
    
    //use maxIndex to find solution
    int gap = 0;
    for(int i=0; i<len; i++)
    {
        if( (maxIndex[i] - index[i]) > gap) gap = maxIndex[i] - index[i];
    }
    
    
    /*for(int i=0; i<len-1;i++)
    {
        if( (len-1-i) <= gap) break; //gap can't possibly be more now
        
        int j = len-1;
        int flag = 0;
        while(j > i)
        {
            if(A[j] >= A[i])
            {
                flag = 1;
                break;
            }
            j--;
        }
        if(flag == 1 && (j-i) > gap) gap = j-i;
    }*/
    
    
    return gap; //if no other cases found then i=j and gap=0
}
