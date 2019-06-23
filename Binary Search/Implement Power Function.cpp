/*Approach 1 of power function
long long int power(long long int x, long long int n)
{
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n == 2) return x*x;
    
    if(n % 2 == 0)
    {
        long long int temp = power(x, n/2);
        
        if(temp >= 0) return temp % INT_MAX;
        else temp = temp % INT_MIN;
        
        if(temp >= 0) return (temp*temp) % INT_MAX;
        else return (temp*temp) % INT_MIN;
    }
    else
    {
        long long int temp = power(x, (n-1)/2);
        if(temp >= 0) temp = temp % INT_MAX;
        else temp = temp % INT_MIN;
        
        if(temp >= 0) return (temp*temp*x) % INT_MAX;
        else return (temp*temp*x) % INT_MIN;
    }
}*/

/*Approach 2 of power function*/
//long long int power(long long int x, long long int n, long long int d){
long long int power(int x,int n, int d){
    if(n == 0) return 1;
    
    else if(n % 2 == 0)//even
    {
        return (power((x*x)%d, n/2, d));
    }
    else if(n % 2 == 1)
    {
        return (x*power(x,n-1,d))%d;
    }
}


int Solution::pow(int x, int n, int d) {
    
    
    if(d == 0 || d == 1 || x == 0) return 0;
    if( (n == 0 && d != 1) || (x == 1 && d != 1) ) return 1;
    if( (n == 0 && d == 0) || (x == 1 && d == 1) ) return 0;
    
    //Approach 2: To do x^n, if n is even, keep calculating half of it recursively and 
    //multiply by itself to reduce multiplication.
    //if odd then do it for n-1 then at the end multiply x
    
    long long int ans, powAns;
    
    powAns = power(x%d,n,d);
    ans = powAns; 
    //% d;
    
    if(ans > 0) return ans;
    else return (d + ans) % d; //-1 becomes 19 i..e 20-1
    
    //Approach-1:
    //answer repeats in buckets of (d-1) times
    //i.e. 2%3 = 2, 4%3 = 1, here d=3, d-1 = 2 so repeats after 2 times
    //i.e. 8 % 3 = 2 again, 16%3 = 1 again and so on
    
    //long long int temp = x;
    //long long int ans, i = 1;
    
    /*long long int duplicateFoundAtPos = (n-1) % (d-1); //n-1 denotes position too
    //Now fill it till this position
    
    while(i <= duplicateFoundAtPos)
    {
        temp *= x;
        i++;
    }
    
    ans = temp % d;*/
}


//CORRECT SOLUTION-
/*int Solution::pow(int x, int n, int p) 
{
    if (n == 0) 
        return 1 % p;

    long long ans = 1, base = x;
    while (n > 0) 
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % p;
            n--;
        } 
        else
        {
            base = (base * base) % p;
            n /= 2;
        }
    }
    if (ans < 0) 
        ans = (ans + p) % p;
    return ans;
}
*/

