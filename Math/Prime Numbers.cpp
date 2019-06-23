vector<int> Solution::sieve(int A) {
    
    vector<int> allNos;
    vector<int> isPrime;
    
    if(A < 2) return allNos;
    
    if(A == 2) 
    {
        allNos.push_back(2);
        return allNos;
    }
    
    for(int i=1; i<=A;i++)
    {
        allNos.push_back(i);
        isPrime.push_back(1);
    }
    
    isPrime[0] = 0;
    
    for(int i=1; i<=((int)sqrt(A)); i++) //index
    {
        int num = i+1; //number stored at that index
        int j = i + num;
        while (j < A)
        {
            if(isPrime[j] == 1) isPrime[j] = 0;
            
            j += num;
        }
        
    }
    
    vector<int> ans;
    for(int i=0; i<A; i++)
    {
        if(isPrime[i] == 1) ans.push_back(allNos[i]);
    }
    
    return ans;
}
