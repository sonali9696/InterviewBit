string Solution::simplifyPath(string A) {
    
    stack<string> s;
    vector<string> v;
    string ret = "", temp;
    int i, sz;
    sz = A.size();
    for (i = 0; i < sz; i++) {
        if (isalpha(A[i])) {
            temp = A[i];
            while(i+1 < sz && isalpha(A[i+1]))
                temp += A[i+1], i++;
            s.push(temp);
        } else if (A[i] == '.') {
            if (i+1 < sz && A[i+1] == '.') {
                i++;
                if (s.size())
                    s.pop();
            }
        }
    }
    while (s.size()) {
        temp = '/'+s.top();
        v.push_back(temp); s.pop();
    }
    for (i = v.size()-1; i >= 0; i--)
        ret += v[i];
    if (ret == "")
        ret = "/";
    return ret;
    
    /*string ans;
    int beg;
    if(A[0] != '/') {
        beg = 0;
        ans = "";
    }
    else{
      beg = 1;
      ans = "/";
    } 
    
    int l = A.size();
    stack<string> st;
    
    for(int i=beg; i<l; i++)
    {
        if(A[i] == '/') //single slash separator
        {
            if(ans[ans.size()-1] != '/') continue;
            if(i!=l-1)
            {
                ans += "/";
                continue;
            }
            else
                break;
        }
        
        else if(A[i] == '.' && (i == l-1 || A[i+1] != '.') )
        {
            //stay where you are
            i++; 
            while(A[i] == '/') i++;
            i--; //just the last / (++ in for loop)
        }
        else if(A[i] == '.' && i!= l-1 && A[i+1] == '.')
        {
            i++;
            //go to parent directory
            if(st.empty()) ans = "/";
            else
            {
                ans += st.top();
                st.pop();
            }
        }
        else //string
        {
            string temp = "";
            while(i<l && A[i] != '/')
            {
                temp += A[i];
                i++;    
            }
            ans += temp;
            if(i == l-1) break;
            else if(ans[ans.size()-1] != '/')
            {
                ans += "/";
            }
        }
        
    }
    
    return ans;
    */
}
