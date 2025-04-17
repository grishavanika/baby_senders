# 3.12.4 is required because of C++20 support.
cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)
project(baby_senders LANGUAGES CXX)

# beman::execution
include(FetchContent)
FetchContent_Declare(
  execution
  GIT_REPOSITORY https://github.com/bemanproject/execution.git
  GIT_TAG        2e55510aa71e467c94d9c45b013c7cb83acd37b6
  GIT_SHALLOW    TRUE
  )
FetchContent_MakeAvailable(execution)

# baby_senders
add_executable(baby_senders main.cc)
set_property(TARGET baby_senders PROPERTY CXX_STANDARD 20)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT baby_senders)
target_link_libraries(baby_senders PRIVATE beman::execution)
