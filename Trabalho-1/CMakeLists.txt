cmake_minimum_required (VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v1.12.1)

FetchContent_MakeAvailable(Catch2)


# Project name
project (Trabalho-1)

set (SOURCE_DIR .)
set (INCLUDE_DIR .)

set (HEADER_FILES 
    ${INCLUDE_DIR}/velha.hpp
)   
set (SOURCE_FILES 
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/velha.cpp
)

# Executable name
add_executable (T1-MP ${DOMAINS_SOURCE_FILES}
                            ${SOURCE_FILES}
)
target_include_directories(T1-MP PUBLIC ${INCLUDE_DIR})

# build tests
set(testing_sources ${SOURCE_FILES} ${SOURCE_DIR}/testa_velha.cpp)

# remove main from sources
list(REMOVE_ITEM testing_sources ./main.cpp)


# Executable tester 
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
add_executable (t1-mp-test ${testing_sources} ${test_files})
target_include_directories(t1-mp-test 
                           PRIVATE
                           Catch2::Catch2
                           ${INCLUDE_DIR}
)
include(CTest)
