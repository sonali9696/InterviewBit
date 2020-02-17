vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    int l = A.size();
    vector<vector<int> > ans;
    
    if(l == 0) return ans;

    unordered_map <string, vector<int> > m;
    string s;
    
    //sort the characters in the string so that the anagrams become equal
    for(int i = 0; i < l; i++)
    {
        s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i+1);
    }
    
    int l2 = m.size();
    
    for(auto i = m.begin(); i != m.end(); i++)
    {
        ans.push_back(i->second);
    }
    
    return ans;
}
