int Solution::isPalindrome(int A) {
    if(A<0) return 0;
    
    string s = to_string(A);
    string t = s;
    if(s.length() <= 1) return 1;
    
    reverse(t.begin(), t.end());
    
    //if(strcmp(s,t) == 0) return 1;
    if(s.compare(t) == 0) return 1;
    else return 0;
    
}
