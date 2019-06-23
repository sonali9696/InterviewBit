//For m*n matrix:
//m-1 steps down, n-1 steps right. Total steps = m+n-2.
//let down be represented by 0, right by 1
//so all combos of string of length=m+n-2 with m-1 times 0, and n-1 times 1
//so ans is (m+n-2)C(m-1)
//=(m+n-2)! / (m-1)!(n-1)!
//=(m+n-2)...(m)/(n-1)! if m > n else vice versa

/*int fact(int begin,int end)
{
    int prod = 1;
    for(int i=begin; i<=end; i++) prod *= i;
    return prod;
}
*/
int Solution::uniquePaths(int A, int B) {
    if(A == 1 || B == 1) return 1;
    
    int m,n;
    if(A < B) //n is the bigger one
    {
        m = A;
        n = B;
    }
    else
    {
        m = B;
        n = A;
    }    
    double ans = 1;
    
    for(int i=1; i<=m-1; i++)
    {
        ans *= (i+n-1);
        ans /= (i);
    }
    
/*    int upto,den;
    
    if(m > n) {
        den = n-1;
        upto = m;
    }
    else {
        den = m-1;
        upto = n;
    }
    
    den = fact(1,den);
    int num = fact(upto,m+n-2);
    
    cout<<"den="<<den<<endl;
    cout<<"num="<<num<<endl;
    
    ans = (num/den);
    cout<<"ans="<<ans<<endl;
    return (int)ans;*/
    
    /*double ans=1;
    
    while(den != 0)
    {
        ans *= (num)/(den);
        num--;
        den--;    
    }*/
    
    return (int) ans;
}

