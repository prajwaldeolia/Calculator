cmake_minimum_required(VERSION 3.20)
project(Ass4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package (SQLite3)
FIND_LIBRARY(SQLITE3_LIBRARY NAMES sqlite3)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries (${OUT_TARGET} ${SQLite3_LIBRARIES})


# find_package (sqlite3)
# if (SQLITE3_FOUND)
#   include_directories(${SQLITE3_INCLUDE_DIRS})
#   target_link_libraries (new ${SQLITE3_LIBRARIES})
# endif (SQLITE3_FOUND)

# include(CTest)
# enable_testing()

add_executable(Ass4 main.cpp)
# set(CPACK_PROJECT_NAME ${Ass4})
# include(CPack)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)