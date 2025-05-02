add_library(art STATIC art.cpp)
target_include_directories(art PUBLIC ${CMAKE_SOURCE_DIR}/library/art/include/)
target_link_libraries(grepster PRIVATE art)