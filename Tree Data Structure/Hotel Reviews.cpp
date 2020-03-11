struct Trie
{
    bool isEndOfWord;
    Trie *children[26];
};

struct Trie* getNode()
{
    struct Trie* ptr = new Trie;
    ptr->isEndOfWord = false;
    for(int i=0; i<26; i++)
    {
        ptr->children[i] = NULL;
    }
    
    return ptr;
}

struct Trie* insert(struct Trie* root, string key)
{
    struct Trie* ptr = root;
    int l = key.length();
    //cout<<"Key entered insert "<<key<<endl;
    
    for(int i=0; i<l; i++)
    {
        int index = key[i] - 'a';
        //cout<<"key[i]="<<key[i]<<", index="<<index<<endl;
        if(ptr->children[index] == NULL)
        {
            ptr->children[index] = getNode();
            ptr = ptr->children[index];
            //cout<<"New node formed"<<endl;
        }
        else
        {
            ptr = ptr->children[index];
            //cout<<"Node exists, moved ptr"<<endl;
        }
    }
    ptr->isEndOfWord = true;
    
    return root;
}

bool search(struct Trie* root, string key)
{
    //cout<<"Key entered search "<<key<<endl;
    
    struct Trie* ptr = root;
    int l = key.length();
    for(int i=0; i<l; i++)
    {
        int index = key[i] - 'a';
        //cout<<"key[i]="<<key[i]<<", index="<<index<<endl;
        if(ptr->children[index] == NULL)
        {
            //cout<<"false"<<endl;
            return false;    
        }
        else
        {
            //cout<<"child found, moving ptr"<<endl;
            ptr = ptr->children[index];
        }
    }
    
    //cout<<"isEndOfWord="<<ptr->isEndOfWord<<endl;
    if(ptr != NULL && ptr->isEndOfWord == true)
    {
        return true;
    }
    else return false;
}

bool comp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second) //same score 
        return a.first < b.first;
    
    return a.second > b.second;	
}


vector<int> Solution::solve(string A, vector<string> &B) {
    struct Trie* root = getNode();
    
    int l = A.length();
    string key = "";
    
    //construct trie
    for(int i=0; i<l; i++)
    {
        if(A[i] != '_') key = key + A[i];
        
        if(A[i] == '_' || i == l-1)
        {
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            //cout<<"Inserting "<<key<<endl;
            if(key != "") root = insert(root, key);
            key = "";
        }
    }
    
    //search reviews in B for matching words
    int l2 = B.size(); //no of reviews;
    vector<pair<int, int> > v; //review index, score
    
    for(int j=0; j<l2; j++)
    {
        //in each review separate words to get score
        string review = B[j];
        int l3 = review.length();
        key = "";
        int score = 0;
        for(int i=0; i<l3; i++)
        {
            if(review[i] != '_') key = key + review[i];
            
            if(review[i] == '_' || i == l3-1)
            {
                bool found = false;
                transform(key.begin(), key.end(), key.begin(), ::tolower);
                if(key != "") found = search(root, key);
                //cout<<"Searching "<<key<<endl;
                //cout<<"Found = "<<found<<endl;
                if(found == true)
                {
                    score++;
                    //cout<<"Score = "<<score<<endl;
                }
                
                key = "";
            }
        }
        pair<int, int> p = make_pair(j, score);
        //cout<<"Review = "<<review<<", Score = "<<score<<endl;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end(), comp);
    
    vector<int> ans;
    vector<pair<int, int> >::iterator it;
    for(it = v.begin(); it != v.end(); it++)
    {
        ans.push_back(it->first);
    }
    
    return ans;
}
