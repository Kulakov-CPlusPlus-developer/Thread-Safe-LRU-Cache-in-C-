#include <iostream>
#include "Cache.h"
#include <string>
using namespace std;

int main() {
    int size;
    cout << "Input size cache: " << endl;
    cin >> size;
    Cache* cache = new Cache(size);
    string command;
    string key;
    int value;

    while (true) {
        cout << "Enter command: ";
        cin >> command;
        if (command == "exit") {
            break;
        }
        else if (command == "insert") {
            cin >> key >> value;
            cache->put(key,value);
        }
        else if (command == "remove") {
            cin >> key;
            cache->remove(key);
        }
        else if (command == "search") {
            cin >> key;
            cout << cache->get(key) << endl;
        }
        else if (command == "check") {
            cin >> key;
            if (cache->contains(key)) {
                cout << "true" << endl;
            }
            else cout << "false" << endl;
        }
        else if (command == "size") {
            cout << cache->size() << endl;
        }
        else if (command == "capacity") {
            cout << cache->capacity() << endl;
        }
    }
    delete cache;
    return 0;
}
