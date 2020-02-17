vector<string> Solution::prettyJSON(string A) {
    
    //cout<<"A="<<A<<endl;
    
    vector<string> ans;
    int numOfTabs = 0;
    
    int len = A.length();
    //cout<<"len="<<len<<endl;
    
    for(int i=0; i<len; i++)
    {
        string temp = "";
        int flag = 0;
        
        //cout<<"i="<<i<<endl;
        
        for(int j = 0; j < numOfTabs; j++)
        {
            temp = temp + '\t';
        }
        
        while(i<len && A[i] != '[' && A[i] != '{' && A[i] != ',' 
            && A[i] != '}' && A[i] != ']')
        {
            //cout<<"A[i] here = "<<A[i]<<endl;
            flag = 1;
            temp = temp + A[i];
            i++;
        }
         
        if(A[i] == ',')
        {
            temp = temp + ',';
            ans.push_back(temp);
            
            //cout<<"here1"<<endl;
            //cout<<temp<<endl;
            
            continue;
        }
        else if(A[i] == '[' || A[i] == '{')
        {
            if(flag == 1) 
            {
                ans.push_back(temp);
                //cout<<"here2"<<endl;
                //cout<<temp<<endl;
            }
            
            temp = "";
            for(int j = 0; j < numOfTabs; j++)
            {
                temp = temp + '\t';
            }
            temp = temp + A[i];
            if(A[i+1] == ',')
            {
                i++;
                temp = temp + A[i];
            }
            ans.push_back(temp);
            
            //cout<<"here3"<<endl;
            //cout<<temp<<endl;
            
            numOfTabs++;
            continue;
        }
        else if(A[i] == ']' || A[i] == '}')
        {
            if(flag == 1) 
            {
                ans.push_back(temp);
                //cout<<"here4"<<endl;
                //cout<<temp<<endl;
            }
            
            temp = "";
            numOfTabs--;
            
            for(int j = 0; j < numOfTabs; j++)
            {
                temp = temp + '\t';
            }
            temp = temp + A[i];
            if(A[i+1] == ',')
            {
                i++;
                temp = temp + A[i];
            }
            ans.push_back(temp);
            
            //cout<<"here5"<<endl;
            //cout<<temp<<endl;
            
            continue;
        }
        else 
        {
            ans.push_back(temp);
            //cout<<"here6"<<endl;
            //cout<<temp<<endl;
        }
        
    }
    
    return ans;
    
}
