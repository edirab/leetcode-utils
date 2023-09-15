cmake_minimum_required(VERSION 3.1...3.22)

project(leetcode_utils
        VERSION 1.0.0
        LANGUAGES CXX
        DESCRIPTION "Utils for leetcode problems: arrays and binary trees"
)

find_package(GTest REQUIRED)
set(CMAKE_DEBUG_POSTFIX "d")

add_compile_options(
    # -Werror

    # -Wall
    # -Wextra
    # -Wpedantic

    # -Wcast-align
    # -Wcast-qual
    # -Wconversion
    # -Wctor-dtor-privacy
    # -Wenum-compare
    # -Wfloat-equal
    # -Wnon-virtual-dtor
    # -Wold-style-cast
    # -Woverloaded-virtual
    # -Wredundant-decls
    # -Wsign-conversion
    # -Wsign-promo
)

add_library( leetcode_utils SHARED
    src/codec.cpp
    src/traversals.cpp
    src/generator.cpp
    src/random.cpp
    src/visualize.cpp
)

target_compile_features(leetcode_utils PUBLIC cxx_std_20)

target_include_directories( leetcode_utils
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)


message(STATUS "Current configuration: ${CMAKE_BUILD_TYPE}")
set(ENABLE_TESTS ON)

if ( ENABLE_TESTS )
    message(STATUS "Enabling building tests...")
    add_subdirectory(tests)
endif()

# Installs to /usr/local/lib
install (TARGETS leetcode_utils
    LIBRARY DESTINATION lib)

# to /usr/local/include
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)