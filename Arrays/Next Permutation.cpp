void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int n = A.size();
    int ind = n-1;
    
    int small = INT_MAX, smallInd=n-1; //if 1,2,3 then sufix=3 so smallest=n-1(doesn't enter for loop)
    while(ind >= 0 && A[ind-1] > A[ind]) //find the first number where left < right
    {
        ind--;
    }
    
    ind--; //now ind is the location to be swapped
    
    int start = ind+1;//find the next bigger
    for(int i=n-1; i>=start; i--)
    {
        if(A[i] > A[ind])
        {
            small = A[i];
            smallInd = i;
            break;
        }
    }
    
    if(ind != -1) //swap with the next bigger in suffix
    {
        int temp = A[smallInd];
        A[smallInd] = A[ind];
        A[ind] = temp;
    }
    //reverse the suffix/entire thing(if ind==-1)
    
    start = ++ind;//starting location of suffix
    int end = n-1;    
    while(start < end)
    {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
    
}
