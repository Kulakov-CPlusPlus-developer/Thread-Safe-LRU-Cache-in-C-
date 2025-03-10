
#include "Cache.h"
#include "gtest/gtest.h"

TEST(ExampleTest, AlwaysTrue) {
    EXPECT_EQ(1, 1);
    ASSERT_TRUE(true);
}

TEST(CacheTest, PutAndGet) {
    Cache cache(10);
    cache.put("key1", 123);
    ASSERT_EQ(cache.get("key1"), 123);
}

TEST(CacheTest, Remove) {
    Cache cache(10);
    cache.put("key1", 123);
    cache.remove("key1");
    ASSERT_EQ(cache.get("key1"), -1);
}

TEST(CacheTest, LRUWorks) {
    Cache cache(2);
    cache.put("key1", 1);
    cache.put("key2", 2);
    cache.put("key3", 3);
    ASSERT_EQ(cache.get("key1"), -1);
    ASSERT_EQ(cache.get("key2"), 2);
    ASSERT_EQ(cache.get("key3"), 3);
}