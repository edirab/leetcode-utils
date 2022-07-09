
message(STATUS "Building tests: ")

add_executable( test_codec.out
codec/main.cpp    
)

add_executable( test_traversals.out
traversals/main.cpp    
)

add_executable( test_random.out
random/main.cpp
)

target_link_libraries(
test_codec.out PRIVATE leetcode_utils
)

target_link_libraries(
test_traversals.out PRIVATE leetcode_utils
)

target_link_libraries(
test_random.out PRIVATE leetcode_utils
)


