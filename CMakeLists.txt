cmake_minimum_required(VERSION 3.8)
project(myCompiler)

message("-- Generating lexer and parser codes")
# find Flex/Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# generate lexer/parser

 flex_target(Lexer src/lexer.l ${CMAKE_CURRENT_LIST_DIR}/src/lexer.cpp)
 bison_target(Parser src/parser.y ${CMAKE_CURRENT_LIST_DIR}/src/parser.tab.cpp)
 add_flex_bison_dependency(Lexer Parser)

# project include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# all of C/C++ source files
file(GLOB_RECURSE CXX_SOURCES "src/*.cpp")
set(SOURCES  ${CXX_SOURCES} 
            ${FLEX_Lexer_OUTPUTS} ${BISON_Parser_OUTPUT_SOURCE})

# executable
add_executable(compiler ${SOURCES})
set_target_properties(compiler PROPERTIES C_STANDARD 11 CXX_STANDARD 17)
