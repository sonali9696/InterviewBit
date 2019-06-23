void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len = A.size();
    if(len <= 1) return;
    
    /* Approach-1
    
    vector<int> b;
    
    for(int i=0; i<len; i++)
    {
        b.push_back(A[A[i]]);
    }
    
    for(int i=0; i<len; i++)
    {
        A[i] = b[i];
    }*/
    
    //Approach -2
    
    //Step-1: find number of digits in N-1
    /*int num = 0, temp = len-1;
    while(temp > 0)
    {
        num++;
        temp /= 10;
    }
    
    //int multiplier = pow(10, num);
    int multiplier = N;
    
    for(int i=0; i<len; i++)
    {
        A[i] = A[i] * multiplier;
    }
    
    for(int i=0; i<len; i++)
    {
        int newNum = A[ (A[i] / multiplier) ];
        if(newNum % multiplier == 0) //new number was not added ye
        {
            A[i] = A[i] + (A[ (A[i] / multiplier) ]) / multiplier;
        }
        else //it's already modified before
        {
            int originalNum = newNum / multiplier;
            A[i] = A[i] + originalNum;
        }
    }
    
    for(int i=0; i<len; i++)
    {
        int newNum = A[i] % multiplier;
        A[i] = newNum;
    }*/
    
    
    //Approach-3: do above process but instead of pow(10,N-1), multiplier=N;
    int N = len;
    for(int i=0; i<len; i++)
    {
        int newNum = A[A[i]];
        if(newNum < N) //unchanged
            A[i] = A[i] * N + (newNum % N);
        else
        {
            int originalNewNum = newNum/N;
            A[i] = A[i] * N + originalNewNum;
        }
    }
    
    //Getting back just new numbers
    for(int i=0; i<len; i++)
    {
        A[i] = A[i] % N;
    }
}
