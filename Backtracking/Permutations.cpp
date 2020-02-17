void computePermutation(vector<int> A, int used[], vector<vector<int> > &ans,
            vector<int> temp, int pos)
{
    if(pos == A.size() - 1) 
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < A.size(); i++)
    {
        if(used[i] != 1)
        {
            temp.push_back(A[i]);
            used[i] = 1;
            pos++;
            computePermutation(A, used, ans, temp, pos); 
            
            //reset for next iteration
            used[i] = 0;
            pos--;
            temp.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {

    const int l = A.size();
    
    int used[l];
    for(int i = 0; i < l; i++)
    {
        used[i] = 0;
    }
    
    //memset(used,0,sizeof(memset))
    vector<vector<int> > ans;
    
    for(int i=0; i<l; i++)
    {
        vector<int> temp;
        temp.push_back(A[i]);
        int pos = 0; //pos of temp that is filled
        used[i] = 1; //this position is used
        computePermutation(A, used, ans, temp, pos);  
        
        //reset for next iteration
        used[i] = 0;
        temp.clear();
    }
    
    return ans;
}
