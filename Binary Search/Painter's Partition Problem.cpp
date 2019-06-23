bool isPossible(int T, int K, int B, vector<int> &C)
{
    long long int len = C.size();
    long long int i=0;
    long long int timeSpent = 0;
    while(K > 0 && i < len)
    {
        long long int var = timeSpent % 10000003 + B*C[i] % 10000003;
        var  = var % 10000003;
        
        if(var < 0)//too high
            return 0;
        
        if( var > T) //the same painter can't do it
        {
            K--;
            timeSpent = 0; //for the new painter
        }
        else if(var <= T)
        {
            timeSpent = var;
            i++;
        }
    }
    
    if(K > 0 || i == len) return 1;
    else return 0;
    
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long int len = C.size();
    
    if(B == 0) return 0;
    if(A == 0) return INT_MAX;
    if(C.size() == 0) return 0;
    
    int TempB = B;
    B = 1;
    
    //max time possible
    long long int temp = 0;
 
    for(int i=0; i<len; i++)
    {
        temp += C[i]; 
    }
    
    long long int maxTime = B*temp;
    
    //binary search for selecting T 
    long long int beg = 0, end = maxTime % 10000003;
    int mid;
    long long int ans = end; //worst case scenario
    
    while(beg <= end)
    {
        mid = ((beg+end)/2) % 10000003;
        if(mid < 0) break;
        bool possible = isPossible(mid, A, B, C);
        if(possible == 1) 
        {
            ans = mid;//to store last possible time
            end = mid-1;
        }
        else beg = mid+1;
    }
    
    
    return (ans*TempB) % 10000003;
}
