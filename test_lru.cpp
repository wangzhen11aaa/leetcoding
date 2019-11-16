#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// class LRUCache {
// public:

//     LRUCache(int capacity):_capacity(capacity), _current_capacity(0){
//         header = new cacheItem(-1, -1);
//     }
    
//     int get(int key) {
//         if(_capacity==0) return -1;
//         auto find_ret = cache.find(key);
//         if(find_ret==cache.end()) { return -1;}
//         else{
//             if(_current_capacity>1) {
//                 cacheItem *prev = find_ret->second->prev;
//                 prev->next=find_ret->second->next;
//                 if(find_ret->second->next !=nullptr){
//                     find_ret->second->next->prev=prev;
//                 }
//                 if(find_ret->second==evict_pointer){
//                     evict_pointer=evict_pointer->prev;
//                 }
//                 //reinsert item after header.
//                 find_ret->second->next=header->next;
//                 header->next=find_ret->second;
//                 find_ret->second->prev=header;
//                 find_ret->second->next->prev=find_ret->second;
//                 }
                
//         }
//         return find_ret->second->_value;
//     }
    
//     void put(int key, int value) {
//         // If we already have this key in cache.
//         auto find_ret = cache.find(key);
//         if(find_ret!=cache.end()) {
//             if(find_ret->second==evict_pointer){
//                 cacheItem *tmp = evict_pointer;
//                 evict_pointer=tmp->prev;
//                 delete tmp;
//                 _current_capacity--;
//                 cache.erase(key);
//             }
//         }
//         //Insert directly after the header.
//         cacheItem *tmp = new cacheItem(key, value);
//         tmp->next = header->next;
//         header->next = tmp;
//         tmp->prev = header;
//         if(tmp->next != nullptr){
//            tmp->next->prev = tmp;
//         }
//         _current_capacity++;
//         cache.insert(std::pair<int, cacheItem*>(key, tmp));
//         if(_current_capacity <= _capacity){
//            if(_current_capacity==1){
//                // The first item should be pointed.
//                 evict_pointer=tmp;
//             }
//         }
//         else{
//             // evict the last one, and update the evict_pointer.
//             cacheItem *tmp = evict_pointer;
//             evict_pointer=tmp->prev;
//             cache.erase(tmp->_key);
//             delete tmp;
//             _current_capacity--;
//         }
//     }
// private:
//     struct cacheItem {
//         cacheItem(int key, int value):  _key(key),_value(value), next(nullptr), prev(nullptr) {};
//         struct cacheItem *next, *prev;
//         int _key;
//         int _value;
//     };
//     int _current_capacity;
//     int _capacity;
//     // store the pointer which points to cacheItem.
//     unordered_map<int, cacheItem*> cache;
//     cacheItem *evict_pointer;
//     cacheItem *header;
// }; 
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};
int main(){
    LRUCache lru(2);
    lru.put(1,1); 
    lru.put(2,2);
    cout << lru.get(1);
    lru.put(3,3); // evict 2,and the evict_pointer point to 1.
    cout << lru.get(2);
    lru.put(4,4); // evict 1, and the evict pointer point to 3.
    cout << lru.get(1);
    cout << lru.get(3);
    cout << lru.get(4);
}