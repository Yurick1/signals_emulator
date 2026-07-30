cmake_minimum_required(VERSION 3.31)
project(signals_emulator)

set(CMAKE_CXX_STANDARD 23)

file(GLOB all_lib_sources "src/*")
add_library(signals_emulator STATIC ${all_lib_sources})

# Testing
# Source: https://github.com/google/googletest/blob/main/googletest/README.md
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# GoogleTest run configurations for TDD
file(GLOB all_test_files "test/*.cpp")

# An IDE can insert here values automatically. Please remove them and check before a commit
add_executable(all_tests ${all_test_files})

# Link gtest lib to a test runners
target_link_libraries(all_tests gtest_main)
