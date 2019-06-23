int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len = A.size();
    
    if(len == 0 || len == 1) return -1;
    //if(len == 2) return 1; //as [1 1] is the only valid input
    
    
    
    //Approach 3: just use 2 indices in first array to find 0-n/2 or n/2+1 - n
    //and then n/2 array for finding which element
    
    /*
    int n = len -1;
    vector<int> hasRepetition;
    for(int i=0; i<2; i++) hasRepetition.push_back(0);
    
    //if n = odd, 1-ceil(n/2), ceil(n/2)+1 - n
    int Ind = -1;
    
    for(int i=0; i<len; i++)
    {
        if( 1 <= A[i] && A[i] <= ceil(n/2.0)) hasRepetition[0]++;
        else hasRepetition[1]++;
        
        if(hasRepetition[0] > (ceil(n/2.0) - 1 + 1)) 
        {
            Ind = 0;
            break;
        }
        else if(hasRepetition[1] > ( (n - ( ceil(n/2.0) + 1 ) ) + 1 ))
        {
            Ind = 1;
            break;
        }
    }
    
    
    if(Ind == -1) return -1;
    
    int low = 0, high = 0;
    if(Ind == 0) 
    {
        low = 1;
        high = ceil(n/2.0);
    }
    else
    {
        low = ceil(n/2.0) + 1;
        high = n;
    }
    
    vector <int> range;
    for(int i=0; i<(high-low+1); i++) range.push_back(0);
    
    for(int i=0; i<len; i++)
    {
        if(low <= A[i] && A[i] <= high) 
        {
            if(range[A[i] - low] == 1) return A[i];
            else range[A[i] - low] = 1;
        }
    }*/
    
    
    //Approach 2: storing in array of length:sqrt(n)
    int n = len-1;
    int len2 = ceil((double)sqrt(n));
    
    //if len2 is 0? n is 0? len = 1?
    if(len2 == 0) return -1;
    
    //step 1: check which range has one of the repetition(s)
    vector<int> rangeHavingRepetition;
    for(int i=0; i<len2; i++) rangeHavingRepetition.push_back(0);
    
    int chosenRangeInd = -1;
    for(int i=0; i<len; i++)
    {
        int range = ceil((double)A[i]/(double)len2);
        rangeHavingRepetition[range-1]++;
        int curr_high = len2*range;
        
        if( curr_high <= n  && rangeHavingRepetition[range-1] >  len2)
        {
            chosenRangeInd = range-1; 
            break;
        }
        else if(curr_high > n) //i.e. last or last to last bucket which may not have all numbers
        {
            int lowRange = ((range-1)*len2)+1; //instead of 7-9 just 7 i.e. 1 value in n=7
            int highRange = n;
            int diff = highRange - lowRange + 1;
            
            if(rangeHavingRepetition[range-1] > diff)
            {
                chosenRangeInd = range-1; 
                break;
            }
        }
        //because 2*sqrt(n) - 3*sqrt(n) i.e. for n=9, 7-9 (1-3,4-6,7-9) is at index=2 but ceil=3.
        //cant do floor as 3*sqrt(n)/sqrt(n) = 3 = floor(3) = ceil(3)
        
        //Note: for n=7, it again has 1-3,4-6,7-9 even though last one can only store 7.
    }
    
    if(chosenRangeInd == -1) return -1;
    
    //reusing the array
    for(int i=0; i<len2; i++) rangeHavingRepetition[i] = 0;
    
    for(int i=0; i<len; i++)
    {
        //suppose for 4-6, chosenRangeInd = 1 i.e. sqrt(n)+1 - 2*sqrt(n)
        if( (len2*chosenRangeInd) + 1 <= A[i] && A[i] <= len2 * (chosenRangeInd+1))
        {
            int resetIndex = A[i] - ((len2*chosenRangeInd) + 1);
            
            if(rangeHavingRepetition[resetIndex] == 1)
                return A[i];
            else 
                rangeHavingRepetition[resetIndex] = 1;
        }
        
    }
    
    
    //Approach 1: storing in array of length n
    /*vector<int> isPresent;
    for(int i=0; i<len; i++) isPresent.push_back(0);
    
    for(int i=0;i<len;i++)
    {
        if(isPresent[A[i]] == 1) return A[i];
        else isPresent[A[i]] = 1;
    }*/
    
    
    return -1;
}
