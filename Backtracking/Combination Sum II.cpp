void combo(vector<int> &A, int pos, int B, vector<int> temp, vector<vector<int> > &ans,
            int curr_sum)
{

    if(pos >= A.size()-1) return;
    
    for(int i = pos + 1; i < A.size(); i++)
    {
        if(A[i] >= B) break;
        
        int new_sum = curr_sum + A[i];
        if(new_sum > B) break;
        if(new_sum == B)
        {
            temp.push_back(A[i]);
            if(find(ans.begin(), ans.end(), temp) == ans.end()) //not a duplicate
                ans.push_back(temp);
            temp.clear();//it was only for combo and shouldn't affect other sets
            break;
        }
        if(new_sum < B)
        {
            temp.push_back(A[i]);
            combo(A, i, B, temp, ans, new_sum);
            temp.pop_back(); //it was only for combo and shouldn't affect other sets
        }
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] > B) break;
        if(A[i] == B) 
        {
            vector<int> tempVec;
            tempVec.push_back(A[i]);
            if(find(ans.begin(), ans.end(), tempVec) == ans.end()) //not a duplicate
                ans.push_back(tempVec);
            break;
        }
        vector<int> temp;
        temp.push_back(A[i]);
        combo(A, i, B, temp, ans, A[i]);
    }
    
    return ans;
    
}
