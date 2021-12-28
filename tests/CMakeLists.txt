project(unitest)

find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE UNIT_TESTS *.cpp)

foreach(T ${UNIT_TESTS})
    get_filename_component(TEST_NAME ${T} NAME_WE)
    message("Build unit test ${TEST_NAME}")
    add_executable(${TEST_NAME} ${T})
    target_link_libraries(${TEST_NAME} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main cpp_utils)
endforeach(T)

# add memcheck for special test
find_program(CMAKE_MEMORYCHECK_COMMAND valgrind)
set(CMAKE_MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

function(add_memcheck_test name binary)
  set(memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}")
  separate_arguments(memcheck_command)
  add_test(${name} ${binary} ${ARGN})
  add_test(memcheck_${name} ${memcheck_command} ./${binary} ${ARGN})
endfunction(add_memcheck_test)

add_memcheck_test(base_allocator_memory_leak_test allocator_test)