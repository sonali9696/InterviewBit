string Solution::findDigitsInBinary(int A) {

    string ans = "";
    if(A == 0) return "0";
    while(A > 0)
    {
        int remainderOfNo = A % 2;
        ans = ans + to_string(remainderOfNo);
        A /= 2;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}
