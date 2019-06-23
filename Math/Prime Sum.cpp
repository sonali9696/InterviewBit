vector<int> Solution::primesum(int A) {
    //find primes upto A
    //M-1: see if isPrime(n) and isPrime(A-n); n = 2 to A or n iterating over prime array
    //M-2: While getting a new prime number, simply compare immediately if that prime,A-prime is the answerr
    //to do M-2, can't use sieve as A-n would not have been calculated then.
    
    int flag = 0,i,flag2;
    for(i=2; i<=A/2; i++)
    {
        flag = 0;
        for(int j=2; j<=sqrt(i); j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)//prime no found
        {
           int num = A-i; 
           flag2 = 0;
            for(int j=2; j<=sqrt(num); j++)
            {
                if(num % j == 0)
                {
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0) break;
        }
    }
    
    vector<int> ans;
    ans.push_back(i);
    ans.push_back(A-i);
    return ans;
    
    /*const int n = A;
    int sieve[n];
    
    for(int i=0; i<n; i++) sieve[i] = 1; //prime
    sieve[0] = sieve[1] = 0; //not prime
    
    int hash[n], end = n-1, index=0; //end indicates last position of hash
    int count = 2;
    
    for(int i=2; i<n; i++)
    {
        if(sieve[i] == 0) continue;
        else
        hash[index++] = i; //prime number stored in hash table
        count = 2;
        int j = i*count;
        while(j<n)
        {
            sieve[j] = 0; //not prime
            count++;
            j = i*count;;
        }
    }
    end = index-1;
    cout<<"end="<<end<<"\n";
    
    int i;
    for(i = 0; i<=end; i++)
    {
        if(sieve[A - hash[i]] == 1) break;   
    }*/
    
    /*vector<int> ans;
    ans.push_back(hash[i]);
    ans.push_back(A-hash[i]);
    return ans;*/
}
