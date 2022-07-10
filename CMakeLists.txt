cmake_minimum_required(VERSION 3.1...3.22)

project(leetcode_utils
        LANGUAGES CXX
        DESCRIPTION "Utils for binary trees"
)

add_library( leetcode_utils SHARED
    src/codec.cpp
    src/traversals.cpp
    src/generator.cpp
    src/random.cpp
    src/visualize.cpp
)

target_include_directories( leetcode_utils
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tests)

# Installs to /usr/local/lib
install (TARGETS leetcode_utils
    LIBRARY DESTINATION lib)

# to /usr/local/include
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)