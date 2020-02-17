vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    map<int, int> m; //array value, position
    int l = A.size();
    vector<int> ans;
    vector<int> index1;
    vector<int> index2;
    
    for(int i=0; i<l; i++)
    {
        m[A[i]] = i+1;
    }
    
    int count = 0;
    //for(auto i  = m.begin(); i != m.end(); i++)
    //{
    
    for(int count = 0; count < l; count++)
    {
        int num1 = A[count];
        int pos1 = count+1; //need to handle multiple occurrences of array number
        
        /*cout<<"count="<<count<<endl;
        cout<<"element="<<num1<<endl;
        cout<<"pos1="<<pos1<<endl;*/
        
        int numToFind = B - num1;
        
        //cout<<"finding number:"<<numToFind<<endl;
        
        if(m.find(numToFind) == m.end()) 
        {
            //cout<<"not found"<<endl;
            continue;
        }
        else
        {
            //cout<<numToFind<<" found"<<endl;
            int flag = 0;
            for(int j=0; j<A.size(); j++)
            {
                //cout<<"j="<<j<<endl;
                //cout<<"A[j]="<<A[j]<<endl;
                if(A[j] ==  numToFind)
                {
                    int pos2 = j+1;
                    //cout<<"pos2 is "<<pos2<<endl;
                    if(pos1 == pos2) 
                    {
                        //cout<<"same pos, continue"<<endl;
                        continue;
                    }
                    if(pos1 < pos2)
                    {
                        flag = 1;
                        //cout<<"number found="<<numToFind<<endl;
                        index1.push_back(pos1);
                        index2.push_back(pos2);
                    }
                    else if(pos1 > pos2)
                    {
                        //cout<<"2. number found="<<numToFind<<endl;
                        flag = 1;
                        index1.push_back(pos2);
                        index2.push_back(pos1);
                    }
                    break; //for same number no need to find a higher index2
                }
            }
            
            //continue to find more such elements
            
            /*if(flag == 0) continue;
            else break;*/
            
        }
    }
    
    int l2 = index1.size();
    int min_index2 = INT_MAX;
    int min_index1;
    for(int i=0; i<l2; i++)
    {
        if(min_index2 > index2[i]) 
        {
            min_index2 = index2[i];
            min_index1 = index1[i];
        }
    }
    
    //see if there are multiple min index 2
    int count_index2 = 0;
    for(int i=0; i<l2; i++)
    {
        if(index2[i] == min_index2)
        {
            count_index2++;
            if(count_index2 > 1)
            {
                if(index1[i] < min_index1)
                {
                    min_index1 = index1[i];
                }
            }
        }
    }
    
    if(l2 != 0)
    {
        ans.push_back(min_index1);
        ans.push_back(min_index2);
    }
    
    return ans;
}
