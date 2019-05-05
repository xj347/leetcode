class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> key_map;  
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (key_map.find(key) == key_map.end())
            return -1;
        cache.splice(cache.begin(), cache, key_map[key]);
        key_map[key] = cache.begin();
        return key_map[key]->second;
    }
    
    void put(int key, int value) {
        if (key_map.find(key) == key_map.end())
        {
            cache.push_front(make_pair(key, value));
            key_map[key] = cache.begin();
            if (cache.size() > capacity)
            {
                key_map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else
        {
            key_map[key]->second = value;
            cache.splice(cache.begin(), cache, key_map[key]);
            key_map[key] = cache.begin()
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */