bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1, flag = 0;
    
    while(i<j)
    {
        if(i-j == 1) break;
        
        if(s[i] != s[j])
        {
            flag = 1;
            break;
        }
        
        i++;
        j--;
    }
    
    if(flag == 1) return false;
    else return true;
}

void compute(int pos, string &A, vector<vector<string> > &ans, vector<string> temp)
{
    if(pos > A.length()) return;
    
    if(pos == A.length()) 
    {
        ans.push_back(temp);
        temp.clear();
        return;
    }
    
    for(int end = pos; end < A.length(); end++)
    {
        string s;
        for(int j = pos; j <= end; j++) s.push_back(A[j]);
        
        if(isPalindrome(s))
        {
            temp.push_back(s);
            compute(pos + s.length(), A, ans, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > ans;   
    vector<string> temp;
    compute(0, A, ans, temp);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
