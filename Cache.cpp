#include "Cache.h"
#include <iostream>

using namespace std;


Cache::~Cache() {
    cout << "Destructor called" << std::endl;
}


void Cache::update_lru(const string& key) {
    keys.remove(key);
    keys.push_front(key);
}

void Cache::put(const string& key, const int& value) {
    lock_guard<mutex> lock(mtx);
    if(cache.count(key)) {
        cache[key] = value;
        update_lru(key);

    }else {
        if(cache.size() >= capacity_) {
            cache.erase(keys.back());
            keys.pop_back();
        }
        cache[key] = value;
        keys.push_front(key);
    }
}

int Cache::get(const string& key) {
    lock_guard<mutex> lock(mtx);
    if(cache.count(key)) {
        update_lru(key);
        return cache[key];
    } else {
        cout << "Key not found" << endl;
        return -1;
    }

}

void Cache::remove(const string& key){
    lock_guard<mutex> lock(mtx);
    cache.erase(key);
    keys.remove(key);

}

int Cache::size() {
    lock_guard<mutex> lock(mtx);
    return cache.size();
}

int Cache::capacity() {
    lock_guard<mutex> lock(mtx);
    return capacity_;
}

bool Cache::contains(const string& key) {
    lock_guard<mutex> lock(mtx);
    return cache.count(key);
}
