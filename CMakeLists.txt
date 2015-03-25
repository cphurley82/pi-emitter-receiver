cmake_minimum_required(VERSION 2.6)
project (Pi-Emitter-Receiver)

#Use SystemC
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(SystemC)
include_directories(${SystemC_INCLUDE_DIRS})
link_directories(${SystemC_LIBRARY_DIRS})

include_directories (${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST)

add_executable(emitter-receiver ${SRC_LIST})
target_link_libraries(emitter-receiver systemc)
