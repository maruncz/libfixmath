cmake_minimum_required(VERSION 3.5)

project(libfixmath LANGUAGES CXX C)

SET(COMMON_FLAGS "-Wall -pedantic -Wextra -ffunction-sections -fdata-sections")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS}")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-gc-sections,--print-memory-usage")

include(libfixmath/libfixmath.cmake)
include(tests/tests.cmake)

file(GLOB fixsingen-srcs fixsingen/*.c)
file(GLOB fixtest-srcs fixtest/*.c fixtest/*.h)

add_executable(fixtest ${fixtest-srcs})
target_link_libraries(fixtest PRIVATE libfixmath m)
target_include_directories(fixtest PRIVATE ${CMAKE_SOURCE_DIR})

add_executable(fixsingen ${fixsingen-srcs})
target_link_libraries(fixsingen PRIVATE libfixmath m)
target_include_directories(fixsingen PRIVATE ${CMAKE_SOURCE_DIR})


