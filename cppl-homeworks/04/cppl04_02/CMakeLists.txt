cmake_minimum_required(VERSION 3.10)
project(cppl04_02)

include(FetchContent)
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.7
)
FetchContent_MakeAvailable(catch)


add_executable(cppl04_02 cppl04_02.cpp)

target_link_libraries(cppl04_02 PRIVATE Catch2::Catch2)
