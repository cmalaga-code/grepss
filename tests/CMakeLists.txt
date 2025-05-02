set(TEST_APP "UNIT_TESTS")
set(TEST_SOURCE "test.cpp")
set(TEST_INCLUDES "./")

add_executable(${TEST_APP} ${TEST_SOURCE})
target_include_directories(${TEST_APP} PUBLIC ${TEST_INCLUDES})
#target_sources(${TEST_APP} PRIVATE ${CMAKE_SOURCE_DIR}/lib/fme/fme.cpp)
target_link_libraries(${TEST_APP} PRIVATE Catch2::Catch2WithMain)