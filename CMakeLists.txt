cmake_minimum_required(VERSION 3.8)
project(myCompiler)

message("-- Generating lexer and parser codes")
# find Flex/Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


# generate lexer/parser
 flex_target(Lexer src/lexer.l ${CMAKE_CURRENT_LIST_DIR}/src/lexer.cpp)
 bison_target(Parser src/parser.y ${CMAKE_CURRENT_LIST_DIR}/src/parser.tab.cpp)
 add_flex_bison_dependency(Lexer Parser)

# project include directories
include_directories(/usr/include)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${LLVM_INCLUDE_DIRS})



message("LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})

# all of C/C++ source files
file(GLOB_RECURSE CXX_SOURCES "src/*.cpp" "src/.*hpp")
set(SOURCES  ${CXX_SOURCES} ${FLEX_Lexer_OUTPUTS} ${BISON_Parser_OUTPUT_SOURCE})
# executable
add_executable(compiler ${SOURCES})

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 -Wall")

llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD} support core irreader codegen mc mcparser option)
target_compile_features(compiler PRIVATE cxx_std_17)
target_link_libraries(compiler ${llvm_libs})
