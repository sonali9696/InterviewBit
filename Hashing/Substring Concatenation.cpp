vector<int> Solution::findSubstring(string A, const vector<string> &B) {

    vector<int> ans;
    
    int l = A.length();
    if(l == 0) return ans;
    
    int numWords = B.size();
    int len = B[0].length();
    
    int count = 0;
    map <string, int> m; //word, frequency of occurrence
 
    for(int i = 0; i < numWords; i++)
    {
        if(m.find(B[i]) == m.end()) m[B[i]] = 1;
        else m[B[i]] = m[B[i]] + 1;
    }
        
    int window = numWords*len;
    for(int i = 0; i <= l-window; i++)
    {
        int count = 0;
        for(int j = i; j < i + window; j = j + len)
        {
            string temp = A.substr(j, len);
            if(m.find(temp) == m.end()) //word not found
            {
                //reset map and count
                m.clear();
                for(int i = 0; i < numWords; i++)
                {
                    if(m.find(B[i]) == m.end()) m[B[i]] = 1;
                    else m[B[i]] = m[B[i]] + 1;
                }
                count = 0;
                
                break;
            }
            else
            {
                if(m[temp] != 0) //word expected
                {
                    m[temp]--;
                    count++;
                    
                    
                    if(count == numWords)
                    {
                        map<string,int>::iterator it;
                        int flag = 0;
                        for(it = m.begin(); it != m.end(); it++)
                        {
                            if(it -> second != 0)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        
                        if(flag == 0)
                        {
                            ans.push_back(j - ((numWords-1)*len));
                        } 
                        
                        //reset map and count
                        m.clear();
                        for(int i = 0; i < numWords; i++)
                        {
                            if(m.find(B[i]) == m.end()) m[B[i]] = 1;
                            else m[B[i]] = m[B[i]] + 1;
                        }
                        count = 0;
                        break;
                        
                    }
                    
                    
                }
                else if(m[temp] == 0) //extra occurrence
                {
                    //reset map and count
                    m.clear();
                    for(int i = 0; i < numWords; i++)
                    {
                        if(m.find(B[i]) == m.end()) m[B[i]] = 1;
                        else m[B[i]] = m[B[i]] + 1;
                    }
                    count = 0;
                    
                    break;
                }
            }
        }
    }
    
    /*int window = numWords*len;
    
    int i = 0;
    while(i < l)
    {
        int notfound = 0;
        int removefirst = 0;
        string removeword = "";
        int startInd = i;
        int j;
        
        for(j = i; j < i+window; j++)
        {
            string temp = A.substr(j, len);
            if(m.find(temp) == m.end()) //word not found
            {
                notfound = 1;
                break;
            }
            else //found
            {
                //check frequency
                if(m[temp] != 0)
                {
                    m[temp]--;
                }
                else //this word should not have occurred this many times
                {
                    removefirst = 1;
                    removeword = temp;
                    break;
                }
            }
        }
        
        if(removefirst = 1) //remove first occurrence of said word
        {
            int k = i;
            while(k < l)
            {
                string temp2 = A.substr(k, len);
                if(temp2 == removeword)
                {
                    i = k+len;
                }
                k++;
            }
            continue;
        }
        
        if(notfound == 1) //remove word from window
        {
            i = j + len; 
            continue;
        }
        
        
        //see if all words found
        map<string, int>::iterator it;
        int flag = 0;
        for(it = m.begin(); it != m.end(); it++)
        {
            if(it->second != 0) 
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 0) //all words found
        {
            ans.push_back(startInd);
        }
        
        //reset map and continue;
        m.clear();
        for(int i = 0; i < numWords; i++)
        {
            if(m.find(B[i]) == m.end()) m[B[i]] = 1;
            else m[B[i]] = m[B[i]] + 1;
        }
        
        
        i = i + window;
        
    }*/
   
    /*for(int i = 0; i < l; i = i+len)
    {
        string temp = A.substr(i, len);
        
        if(m.find(temp) == m.end()) //word not in L list
        {
            //reset
            temp.clear();
            m.clear();
            count = 0;
            for(int i = 0; i < numWords; i++)
            {
                if(m.find(B[i]) == m.end()) m[B[i]] = 1;
                else m[B[i]] = m[B[i]] + 1;
            }
            continue;
        }
        else
        {
            if(m[temp] != 0)//not finished covering yet
            {
                m[temp]--;
                count++;
                
                if(count == numWords) 
                {
                    ans.push_back(i - ((numWords-1)*len));
                    
                    //reset map
                    
                    m.clear();
                    for(int i = 0; i < numWords; i++)
                    {
                        if(m.find(B[i]) == m.end()) m[B[i]] = 1;
                        else m[B[i]] = m[B[i]] + 1;
                    }
                    temp.clear();
                    count = 0; //reset
                }
                
            }
            else if(m[temp] == 0) //extra occurrence
            {
                //remove all words and first occurrence
                //change map and count accordingly
                int start = i - ((numWords-1)*len;
                for(int k = start; k < i; k++)
                {
                    string temp2 = A.substr(k, len);
                    if(temp2 != temp)
                    {
                        count--;
                        m[temp2] = m[temp2] + 1;
                    }
                    else //first occurrence found
                    {
                        //m for temp is same as one removed and one added
                        //count same too
                        continue;
                    }
                }
                
            }
        }
        
    }*/
    
    return ans;
    
}
