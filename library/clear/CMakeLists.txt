add_library(clear STATIC clear.cpp)
target_include_directories(clear PUBLIC ${CMAKE_SOURCE_DIR}/library/clear/include/)
target_link_libraries(search PRIVATE clear)
target_link_libraries(grepster PRIVATE clear)