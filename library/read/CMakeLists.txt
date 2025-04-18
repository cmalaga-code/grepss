add_library(read STATIC read.cpp)
target_include_directories(read PUBLIC ${CMAKE_SOURCE_DIR}/library/read/include/)
target_link_libraries(grepster PRIVATE read)