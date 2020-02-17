int Solution::solve(string A) {
    
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    
    int count = 0;
    int len = A.length();
    
    for(int i=0; i<len; i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' ||
            A[i] == 'o' || A[i] == 'u')
            {
                int temp = (len-i)%10003;
                count = ((count % 10003)+temp) % 10003;
            }
    }
    
    return count % 10003;
}
