int Solution::lengthOfLongestSubstring(string A) {
    
    int ans = 0, len = A.length();
    
    if(len == 0 || len == 1) return len;
    
    string temp = "";
    map <char, int> m; //stores character, index
    int startInd = 0;
    
    for(int i = 0; i < len; i++)
    {
        if(m.find(A[i]) == m.end() || m[A[i]] == -1)
        {
            m[A[i]] = i;
            temp = temp + A[i];
            //cout<<A[i]<<" added so temp="<<temp;
        }
        else //repeating letter
        {
            int l1 = temp.length();
            if(l1 > ans)
            {
                ans = l1;
            }
            
            int index = m[A[i]];
            
            //cout<<"current temp="<<temp<<endl;
            temp.clear();
            temp = A.substr(index+1,(i-index));
            
            for(int j = startInd; j<= index; j++)
            {
                m[A[j]] = -1;
            }
            startInd = index+1;
            
            /*cout<<"index+1="<<index+1<<" ";
            cout<<"i-index="<<(i-index)<<" ";
            cout<<"temp="<<temp<<" ";
            cout<<" length = "<<temp.length()<<endl;*/
            
            m[A[i]] = i; //updating map
        }
        
        
    }
    
    if(temp.length() > ans) ans = temp.length();
 
    return ans;   
}
