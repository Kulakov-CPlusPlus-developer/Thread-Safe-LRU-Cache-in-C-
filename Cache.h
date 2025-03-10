#ifndef CACHE_H
#define CACHE_H
#include <list>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <mutex>

using namespace std;

class Cache {
  public:
    Cache(int size) : capacity_(size){};
    ~Cache();
    void put(const string& key, const int& value);
    int get(const string& key);
    void remove(const string& key);
    int size();
    int capacity();
    bool contains(const string& key);
    void update_lru(const string& key);


  private:
  int capacity_ = 100;
  unordered_map <string, int> cache;
  list<string> keys;
  mutex mtx;
};
#endif //CACHE_H
