
cmake_minimum_required(VERSION 3.31.3)

project(Public_Socials VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG c492b4fed1fd7288eacec6fe8d89e37df78d373a.12.0)
FetchContent_MakeAvailable(cpr)

target_link_libraries(Public_Socials PRIVATE cpr::cpr)

add_executable(Public_Socials code.cxx)

