cmake_minimum_required(VERSION 3.1...3.22)

project(leetcode_utils
        LANGUAGES CXX
        DESCRIPTION "Utils for binary trees"
)

add_library( leetcode_utils SHARED
    src/codec.cpp
    src/traversals.cpp
    src/generator.cpp
)

target_include_directories( leetcode_utils
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable( test_codec.out
    tests/codec/main.cpp    
)

add_executable( test_traversals.out
    tests/traversals/main.cpp    
)

target_link_libraries(
    test_codec.out PRIVATE leetcode_utils
)

target_link_libraries(
    test_traversals.out PRIVATE leetcode_utils
)

# Installs to /usr/local/lib
install (TARGETS leetcode_utils
    LIBRARY DESTINATION lib)

# to /usr/local/include
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)