cmake_minimum_required(VERSION 3.5.0)
project(udpSocket VERSION 0.1.0 LANGUAGES C CXX)

include_directories(header)

set(HEADER_DIR "./header")
set(SRC_DIR "./src")

add_executable(udpSocket 
main.cpp 
${HEADER_DIR}/Socket.h
${HEADER_DIR}/SocketUDP.h
${SRC_DIR}/Socket.cpp 
${SRC_DIR}/SocketUDP.cpp)

