int Solution::evalRPN(vector<string> &A) {

    stack<int> st;
    int l = A.size();
    
    for(int i=0; i<l; i++)
    {
        if(A[i] == "+")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int ans = num1 + num2;
            st.push(ans);
        }
        else if(A[i] == "-")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int ans = num1 - num2;
            st.push(ans);    
        }
        else if(A[i] == "*")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int ans = num1 * num2;
            st.push(ans);
        }
        else if(A[i] == "/")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int ans = num1 / num2;
            st.push(ans);
        }
        else if(A[i] == "^")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int ans = pow(num1 , num2);
            st.push(ans);
        }
        else 
        {
            //negative number
            
            int sign = 1;
            
            string temp = A[i];
            int j = 0;
            if(temp[j] == '-') 
            {
                sign = -1;
                j++;
            }
            
            //normal number
            int l2 = temp.size();
            int val = 0;
            for(; j<l2; j++) //"25" to 25
            {
                val = val*10 + (temp[j] - '0');
            }
            val *= sign;
            st.push(val);
        }
    }
    
    return (st.top());
}
