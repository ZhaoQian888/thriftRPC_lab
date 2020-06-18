cmake_minimum_required(VERSION 3.10)
project(credit_excise)
 
set(CMAKE_CXX_STANDARD 11)
 
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
 
set(student_SOURCES
        gen-cpp/Serv.cpp
        gen-cpp/Serv_server.skeleton.cpp
        gen-cpp/student_types.cpp
        gen-cpp/student_constants.cpp
        )
 
# 生成静态库目标
add_library(student STATIC ${student_SOURCES})
target_link_libraries(student thrift)
 
# 同下
add_executable(server gen-cpp/Serv_server.skeleton.cpp)
target_link_libraries(server student thrift)
 
# 生成 demo_client 可执行程序，要求链接 demo 静态库, thrift XX库
add_executable(client client.cpp)
target_link_libraries(client student thrift)