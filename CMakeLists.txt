cmake_minimum_required(VERSION 2.8.1)

set(PROJECT_NAME "Libre_DS")
set(TEST_NAME "Libre_DS_Tests")

file(GLOB_RECURSE LIB_SOURCES src/*)
file(GLOB_RECURSE TEST_SOURCES testsrc/*)

project(${PROJECT_NAME})

include_directories(
	src
)

add_library(
	${PROJECT_NAME}
	${LIB_SOURCES}
)

add_executable(
	${TEST_NAME}
	${TEST_SOURCES}
)

target_link_libraries(
	${TEST_NAME}
	${PROJECT_NAME}
)