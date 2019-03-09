cmake_minimum_required(VERSION 3.12)
project(Networks C)

set(CMAKE_C_STANDARD 99)

#add_executable(week1-server week1/server.status)
add_executable(week4-server week4/server.c)
add_executable(week4-client week4/client.c)

add_executable(week5-server week5/listener.c)
add_executable(week5-client week5/talker.c)

add_executable(dictionary dict/main.c dict/hashmap.h dict/hashmap.c)

add_executable(node-test week7/node.c dict/hashmap.h dict/hashmap.c)