cmake_minimum_required(VERSION 2.8.12)

set(JSFUCK_SRC src/jsfuck.c src/common.c src/stream.c src/token.c)
set(JSFUCK_TRANSPILER_SRC src/transpiler/io.c src/transpiler/transpiler.c)
set(JSFUCK_NAME jsfuck)
set(JSFUCK_VERSION 1.1.0)

project(${JSFUCK_NAME})

if(WIN32)
set(JSFUCK_NAME_STATIC ${JSFUCK_NAME}_s)
else()
set(JSFUCK_NAME_STATIC ${JSFUCK_NAME})
endif()

add_library(${JSFUCK_NAME} SHARED ${JSFUCK_SRC})
add_library(${JSFUCK_NAME}_static STATIC ${JSFUCK_SRC})
add_executable(${JSFUCK_NAME}_transpiler ${JSFUCK_TRANSPILER_SRC})

add_compile_definitions(JSFUCK_SOURCE _CRT_SECURE_NO_WARNINGS)

include_directories("include")

if(WIN32)
target_compile_definitions(${JSFUCK_NAME} PUBLIC JSFUCK_DLL)
endif()

set_property(TARGET ${JSFUCK_NAME} PROPERTY OUTPUT_NAME ${JSFUCK_NAME})
set_property(TARGET ${JSFUCK_NAME}_static PROPERTY OUTPUT_NAME ${JSFUCK_NAME_STATIC})
set_property(TARGET ${JSFUCK_NAME}_transpiler PROPERTY OUTPUT_NAME ${JSFUCK_NAME})

set_target_properties(${JSFUCK_NAME} ${JSFUCK_NAME}_static ${JSFUCK_NAME}_transpiler PROPERTIES
  VERSION               ${JSFUCK_VERSION}
  SOVERSION             1
  MSVC_RUNTIME_LIBRARY  MultiThreadedDLL
)

target_link_libraries("${JSFUCK_NAME}_transpiler" ${JSFUCK_NAME}_static)
