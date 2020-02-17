string Solution::multiply(string A, string B) {
    
    int len1 = A.length();
    int len2 = B.length();
    
    cout<<"len1="<<len1<<endl;
    cout<<"len2="<<len2<<endl;
    
    if(len1 == 1)
    {
        int num = A[0] - '0';
        cout<<"num="<<num<<endl;
        if(num == 0) 
        {
            cout<<"entered"<<endl;
            return "0";
        }
    }
    if(len2 == 1)
    {
        int num = B[0] - '0';
        if(num == 0) return "0";
    }
    
    
    if(len1 < len2)
    {
        string tempString = A;
        A = B;
        B = tempString;
        
        int tempNum = len1;
        len1 = len2;
        len2 = tempNum;
    }
    
    int lenAns = len1 + len2;
    string ans;
    string currAns;
    
    //cout<<"lenans="<<lenAns<<endl;
    
    for(int i = 0; i < lenAns; i++)
    {
        ans.push_back('0');
        currAns.push_back('0');
    }
    
    int numberOfEndingZeros = 0, carry;
    
    //complete multiplication
    for(int i = len2 - 1; i >= 0; i--)
    {
        int numToBeMultiplied = B[i] - '0';
        int zeros = numberOfEndingZeros;;
        int k = lenAns - 1;
        
        carry = 0;
        //filling one line for multiplication
        for(int j = len1 - 1; j >= 0; j--)
        {
            while(zeros != 0)
            {
                currAns[k] = '0';
                zeros--;
                k--;
            }
            
            
            if(k == 0) break;
            
            int result = (numToBeMultiplied * (A[j] - '0')) + carry;
            if(result / 10 == 0) //single digit
            {
                currAns[k] = result + '0';
                carry = 0;
            }
            else
            {
                if(j != 0)
                {
                    currAns[k] = (result % 10) + '0';
                    carry = (result / 10) ;
                }
                else
                {
                    currAns[k] = (result % 10) + '0';
                    currAns[k-1] = (result / 10) + '0';
                    carry = 0;
                }
                
            }
            
            k--;
        }
        
        //cout<<"currAns="<<currAns<<endl;
        
        //summing up the lines
        carry = 0;
        for(int p = lenAns - 1; p >= 0; p--)
        {
            int num1 = ans[p] - '0';
            int num2 = currAns[p] - '0';
            
            int result = num1 + num2 + carry;
            if(result / 10 == 0) //single digit
            {
                ans[p] = result + '0';
                carry = 0;
            }
            else
            {
                if(p > 1)
                {
                    ans[p] = (result % 10) + '0';
                    carry = result / 10;
                }
                else
                {
                    ans[1] = (result % 10) + '0';
                    ans[0] = (result / 10) + '0';
                    carry = 0;
                }
                
            }
            
            currAns[p] = '0';
        }
        
        //cout<<"ans="<<ans<<endl;
        
        numberOfEndingZeros++;
    }
    
    //cout<<"here"<<endl;

    //removing trailing zeroes
    string finalAns;
    int pos = 0;
 
    
    while(pos < lenAns && ans[pos] == '0')
    {
        pos++;
    }
    
    
    for(int i = pos; i < lenAns; i++)
    {
        finalAns.push_back(ans[i]);
    }
    
    //cout<<"finalAns="<<finalAns<<endl;
    
    if(finalAns.length() == 0) //nothing got inserted
        return "0";
    
    return finalAns;
    
    
}
