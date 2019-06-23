void Solution::reverseWords(string &A) {
    int l = A.size();
    
    int beg = l-1;
    
    string ans = "";
    string word = "";
    
    
    //trailing spaces
    while(A[beg] == ' ' && beg >=0 ) beg--;
    
    //first word
    word = "";
        while(beg >= 0 && A[beg] != ' ')
        {
            word = A[beg] + word;
            beg--;
        }
        
    ans += word;
    
    while(beg >= 0)
    {
        //extra spaces
        while(beg >= 0 && A[beg] == ' ')
        {
            beg--;
        }
        
        //separator
        if(beg >= 0) ans += ' ';
        
        //word
        word = "";
        while(beg >= 0 && A[beg] != ' ')
        {
            word = A[beg] + word;
            beg--;
        }
        ans += word;
    
        if(beg == -1) break;
    }
    
    A = ans;
    
}
