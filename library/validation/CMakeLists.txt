add_library(validation STATIC validation.cpp)
target_include_directories(validation PUBLIC ${CMAKE_SOURCE_DIR}/library/validation/include/)
target_link_libraries(grepster PRIVATE validation)