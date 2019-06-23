vector<int> Solution::maxset(vector<int> &A) {
    
    if(A.size() == 0) return A;
    
    long long int sum = 0;
    int negativeNoPresent = 0, i = 0, beg = 0, end = -1;
    
    while(i<A.size())
    {
        if(A[i] < 0) 
        {
            if(negativeNoPresent == 0) negativeNoPresent = 1; 
            i++;
            continue;
        }
        
        long long int tempSum = 0;
        int enteredLoop = 0, tempBegin = i, tempEnd = i;
        while(i<A.size() && A[i] >= 0)
        {
            if(enteredLoop == 0) enteredLoop = 1;
            tempSum = tempSum + A[i];
            tempEnd = i;
            i++;
        }
        
        //usual sum higher - no tie
        if(tempSum > sum)
        {
            sum = tempSum;
            beg = tempBegin;
            end = tempEnd;
        }
        //tie - but size different
        else if(tempSum == sum)
        {
            int size1 = end - beg + 1;
            int size2 = tempEnd - tempBegin + 1;
            if(size2 > size1)
            {
                sum = tempSum;
                beg = tempBegin;
                end = tempEnd;
            }
            //if size2 <= size1 - remain unchanged
        }
        
        if(i == A.size()) 
        {
            break;
        }
        
        if(enteredLoop == 0) i++;
    }

    //Case 1: no negative numbers
    if(negativeNoPresent == 0)
    {
        return A;
    }
    
    //all negative numbers?
    if(end == -1)
    {
        vector <int> B;
        return B;
    }
    
    int size = end-beg + 1;
    vector <int> B;
    for(int i=beg; i<=end; i++)
    {
        B.push_back(A[i]);
    }
    return B;
    
}


