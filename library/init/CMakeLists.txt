add_library(init STATIC init.cpp)
target_include_directories(init PUBLIC ${CMAKE_SOURCE_DIR}/library/init/include/)
target_link_libraries(grepster PRIVATE init)