# 3.20 is required because of C++23 support.
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(baby_senders LANGUAGES CXX)

# beman::execution
include(FetchContent)
FetchContent_Declare(
  execution
  GIT_REPOSITORY https://github.com/bemanproject/execution.git
  GIT_TAG        2e55510aa71e467c94d9c45b013c7cb83acd37b6 # as of 2025/04/17
  GIT_SHALLOW    TRUE
  )
FetchContent_MakeAvailable(execution)

# stdexec
FetchContent_Declare(
  stdexec
  GIT_REPOSITORY https://github.com/NVIDIA/stdexec.git
  GIT_TAG        954159ad82386b3564ea4125d9f4b7a68ccb912c # as of 2025/04/17
  GIT_SHALLOW    TRUE
  )
set(STDEXEC_BUILD_EXAMPLES OFF) # disable projects we don't care
FetchContent_MakeAvailable(stdexec)

# beman_senders
add_executable(beman_senders main.cc)
set_property(TARGET beman_senders PROPERTY CXX_STANDARD 23)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT beman_senders)
target_link_libraries(beman_senders PRIVATE beman::execution)

# stdexec_senders
add_executable(stdexec_senders main.cc)
set_property(TARGET stdexec_senders PROPERTY CXX_STANDARD 23)
target_link_libraries(stdexec_senders PRIVATE STDEXEC::stdexec)
