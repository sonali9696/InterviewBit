int Solution::reverse(int A) {
    // handling digits like 10, 100
    //handling overflow like  -1234567891
    
    long long int ans = 0;
    long long int num = A;
    
    if(num >= INT_MAX || num <= INT_MIN) return 0;
    
    if(num >= pow(10,10)) return 0;
    
    
    while(num != 0)
    {
        if( (ans*10 + num % 10) >= INT_MAX || (ans*10 + num % 10) <= INT_MIN ) return 0;
        ans = ans*10 + num % 10;
        num /= 10;
        //cout<<ans<<endl;
    } 
    
    if(ans >= INT_MAX || ans <= INT_MIN) return 0;
    
    //if(abs(ans) > 4294967295) return 0; //2^32-1 is the overflow limit
    //cout<<"ans="<<ans<<endl;
    return ans;
}
