int bin2dec(int num[], int l)
{
    int ans = 0;
    int power = 0;
    
    for(int i = l-1; i >= 0; i--)
    {
        int temp = num[i] * pow(2,power);
        power++;
        ans = ans + temp;
    }
    
    return ans;
}

//THINK HOW TO RETURN ARRAY

void compute(vector<int> &ans, int number[], int bitToFlip, int count, 
            int numOfBits)
{
    if(bitToFlip < 0) return;
    
    int index = count-1;
    while(index >= 0)
    {
        int num = ans[index];
        //cout<<"num getting converted="<<num<<endl;
        
        //decimal to binary:
        int pos = numOfBits-1;
        
        //reset
        for(int i=0; i<numOfBits; i++) number[i] = 0;
        
        while(num != 0)
        {
            number[pos--] = num % 2;
            num /= 2;
        }
        
        /*cout<<"dec2bin array:"<<endl;
        for(int i=0; i<numOfBits; i++) cout<<number[i]<<" ";
        cout<<endl;*/
        
        number[bitToFlip] = 1;
        int n = bin2dec(number, numOfBits);
        //cout<<"finally pushes "<<n<<endl;
        ans.push_back(n);
        index--;
        count++;
    }

    compute(ans, number, bitToFlip-1, count, numOfBits);
}

vector<int> Solution::grayCode(int A) {
    const int len = A;
    int number[len];
    memset(number, 0, sizeof(number));
    vector<int> ans;
    
    if(A == 0) 
    {
        ans.push_back(0);
        return ans;
    }
    
    int b = bin2dec(number, A);
    //cout<<"main b="<<b<<endl;
    ans.push_back(b);
    
    number[len-1] = 1;
    b = bin2dec(number, A);
    //cout<<"2. main b="<<b<<endl;
    ans.push_back(b);
    
    compute(ans, number, A-2, 2, A);    
    
    return ans;
}
