cmake_minimum_required(VERSION 3.29)
project(Storage)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Storage
        Cache.cpp
        main.cpp
)
add_executable(StorageTest
        Cache.cpp
        tests.cpp
)

target_link_libraries(StorageTest PRIVATE
        gtest_main
        gtest
)

include(GoogleTest)
gtest_discover_tests(StorageTest)