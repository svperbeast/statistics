cmake_minimum_required(VERSION 2.8.12)

project (sts_test)

include_directories (
    ${sts_test_SOURCE_DIR}
    )

add_executable (
    sts_test
    statistics_test.cpp
    )

set_target_properties (
    sts_test
    PROPERTIES
    COMPILE_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++11"
    )
