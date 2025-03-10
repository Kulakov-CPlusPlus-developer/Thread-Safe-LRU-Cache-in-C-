# Thread-Safe LRU Cache in C++

This project implements a Least Recently Used (LRU) Cache with thread safety in C++.

## Description

An LRU Cache is a data structure that stores a limited number of items. When the cache is full, it evicts the item that was used the least recently. This LRU Cache implementation provides thread safety, allowing it to be used in multithreaded applications without data race concerns.

## Functionality

*   **`put(key, value)`:** Adds an item to the cache. If the key already exists, its value is updated. If the cache is full, the least recently used item is evicted.
*   **`get(key)`:** Returns the value associated with the key. If the key is not found, returns -1. When an item is successfully retrieved, it is moved to the front of the LRU list (as the most recently used).
*   **`remove(key)`:** Removes the item from the cache by key.
*   **`size()`:** Returns the number of items in the cache.
*   **`capacity()`:** Returns the maximum capacity of the cache.
*   **`contains(key)`:** Checks if the cache contains the given key.

## Architecture

*   The cache is implemented using `std::unordered_map` for fast access to items by key.
*   A `std::list` is used to track the order of item usage.
*   Thread safety is ensured using `std::mutex`. The mutex protects access to the `std::unordered_map` and `std::list`.
*   The eviction policy is LRU (Least Recently Used).

## Design Decisions

*   Using `std::unordered_map` instead of `std::map` for faster item access (O(1) average, O(n) worst case).
*   Using `std::list` to track the order of item usage, as it provides efficient add and remove operations at the front and back of the list.
*   Using `std::lock_guard` for automatic mutex management, which helps avoid forgetting to release the mutex.
*   The global mutex was replaced with a mutex as a class member to ensure correct multithreading.

## Building and Running

To build and run the project, you will need:

*   A C++ compiler (e.g., g++, clang++) with C++11 or later support.
*   CMake (version 3.15 or higher).
*   Google Test (for running unit tests).

**Steps:**

1.  Clone the repository:

    ```bash
    git clone [Your repository URL]
    cd [Your repository name]
    ```

2.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```

3.  Generate build files using CMake:

    ```bash
    cmake ..
    ```

4.  Build the project:

    ```bash
    cmake --build .
    ```

5.  Run the unit tests (if any):

    ```bash
    ctest .
    ```

6.  Run the main program:

    ```bash
    ./Storage.exe
    ```

## Example Usage

```c++
#include "Cache.h"
#include <iostream>

int main() {
    Cache cache(3); // Create a cache with a capacity of 3 items

    cache.put("key1", 10);
    cache.put("key2", 20);
    cache.put("key3", 30);

    std::cout << "key1: " << cache.get("key1") << std::endl; // Output: key1: 10
    std::cout << "key2: " << cache.get("key2") << std::endl; // Output: key2: 20
    std::cout << "key3: " << cache.get("key3") << std::endl; // Output: key3: 30

    cache.put("key4", 40); // Evicts "key1" (LRU)

    std::cout << "key1: " << cache.get("key1") << std::endl; // Output: key1: -1 (not found)
    std::cout << "key4: " << cache.get("key4") << std::endl; // Output: key4: 40

    return 0;
}
