cmake_minimum_required(VERSION 3.8)
project(FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Library.cpp Book.cpp Member.cpp MemberLinkedQueue.cpp MemberLinkedNode.cpp)
add_executable(FinalProject ${SOURCE_FILES})