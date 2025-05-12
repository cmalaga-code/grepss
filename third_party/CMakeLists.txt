include(FetchContent)


FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 11.1.4
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(fmt)
target_link_libraries(grepster PRIVATE fmt::fmt)
target_link_libraries(search PRIVATE fmt::fmt)
target_link_libraries(art PRIVATE fmt::fmt)
target_link_libraries(init PRIVATE fmt::fmt)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v3.8.1
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Catch2)