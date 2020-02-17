int cache_capacity;
map<int, int> cache; //key,value
//priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
//min heap of time as enum, key
map <int,int> v; //timeline
int t;


LRUCache::LRUCache(int capacity) {
    cache_capacity = capacity;
    cache.clear();
    t = 0;
}

void updateTimeLine(int key)
{
    t++;
    map<int,int>::iterator it;
    for(it = v.begin(); it != v.end(); it++)
    {
        if(it->second == key)
        {
            v.erase(it->first);
            break;
        }
    }
        
    v[t] = key;
}

int findLRUKey()
{
    map<int,int>::iterator it;
    int min = INT_MAX;
    int ans;
    for(it = v.begin(); it != v.end(); it++)
    {
        if(min > it->first) 
        {
            ans = it->second;
            min = it->first;
        }
    }
    
    v.erase(min);
    
    return ans;
}

int LRUCache::get(int key) {
    
    //cout<<"get"<<endl;
    
    if(cache.find(key) != cache.end()) 
    {
        updateTimeLine(key);
        return cache[key];
    }
    else 
    {
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    
    /*cout<<"set"<<key<<" "<<value<<endl;
    cout<<"cache before - "<<endl;
    map<int,int>::iterator it2;
    for(it2 = cache.begin(); it2 != cache.end(); it2++)
    {
        cout<<it2->first<<" "<<it2->second<<endl;
    }
    cout<<"*******"<<endl;*/
    
    if(cache_capacity == 1 && cache.size() == 1)
    {
        cache.clear();
        cache[key] = value;
        updateTimeLine(key);
        return;
    }
    
    if(cache.find(key) != cache.end()) //key already exists so update it
    {
        //cout<<"key exists"<<endl;
        cache[key] = value; 
        updateTimeLine(key);
    }
    else if(cache.size() != cache_capacity)
    {
        //cout<<"capacity not full"<<endl;
        cache[key] = value;
        updateTimeLine(key);
    }
    else if(cache.size() == cache_capacity)//capacity full
    { 
        //cout<<"capacity full"<<endl;
        int keyNeeded = findLRUKey(); //it removes from timeline map too
        
        if(cache.find(keyNeeded) != cache.end()) //present in cache
        {
            cache.erase(keyNeeded);
            cache[key] = value;
        }
        
        updateTimeLine(key);
    }
    
    
    /*cout<<"cache after - "<<endl;
    for(it2 = cache.begin(); it2 != cache.end(); it2++)
    {
        cout<<it2->first<<" "<<it2->second<<endl;
    }
    cout<<"*******"<<endl;*/
}
