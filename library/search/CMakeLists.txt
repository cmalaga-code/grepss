add_library(search STATIC search.cpp)
target_include_directories(search PUBLIC ${CMAKE_SOURCE_DIR}/library/search/include/)
target_link_libraries(grepster PRIVATE search)