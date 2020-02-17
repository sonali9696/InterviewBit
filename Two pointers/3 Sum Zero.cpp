vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    sort(A.begin(), A.end());
    int l = A.size();
    
    //for(int i=0; i<l; i++) cout<<A[i]<<" ";
    //cout<<endl;
    
    vector<vector<int> > ans;
    
    //M-1: brute force
    
    /*for (int i = 0; i < l-2; i++)
    {
        for (int j = i+1; A[j] <= (-1*A[i]); j++)
        {
            if(j == l-1) break;
            
            for(int k = j+1; A[k] <= (-1*(A[i]+A[j])); k++)
            {
                if(k == l) break;
                
                if(A[k] + A[j] + A[i] == 0)
                {
                    vector<int> temp;
                    
                    //maintain non descending
                    int first = A[i], second = A[j], third = A[k];
                    if(A[j] < first) first = A[j];
                    if(A[k] < first) first = A[k];
                    
                    if(first == A[i])
                    {
                        if(A[k] < A[j])
                        {
                            second = A[k];
                            third = A[j];
                        }
                        else
                        {
                            second = A[j];
                            third = A[k];
                        }
                    }
                    else if(first == A[j])
                    {
                        if(A[i] < A[k])
                        {
                            second = A[i];
                            third = A[k];
                        }
                        else
                        {
                            second = A[k];
                            third = A[i];
                        }
                    }
                    else if(first == A[k])
                    {
                        if(A[i] < A[j])
                        {
                            second = A[i];
                            third = A[j];
                        }
                        else
                        {
                            second = A[j];
                            third = A[i];
                        }
                    }
                    
                    temp.push_back(first);
                    temp.push_back(second);
                    temp.push_back(third);
                    
                    //remove duplicates
                    bool isPresent = (find(ans.begin(), ans.end(), temp) != ans.end());
                    if(!isPresent) ans.push_back(temp);
                }
            }
            
        }
    }*/
    
    //M-2: 2 pointer approach
    
    for(int i = 0; i < l-2; i++)
    {
        int j = i+1, k = l-1;
        
        while(j < k)
        {
            if(A[i] + A[j] + A[k] == 0)
            {  
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[j]);
                temp.push_back(A[k]);
                
                //remove duplicates
                bool isPresent = (find(ans.begin(), ans.end(), temp) != ans.end());
                if(!isPresent) ans.push_back(temp);
                
                //find next triplet
                j++;
                k--;
            }
            else
            {
                if(A[i] + A[j] + A[k] > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
    }
    
    
    return ans;
}
