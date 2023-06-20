cmake_minimum_required(VERSION 3.22)
project(simple_cpu)
find_package(verilator HINTS $ENV{VERILATOR_ROOT})
add_executable(simple_cpu ${CMAKE_CURRENT_SOURCE_DIR}/tb/test_beach.cpp)
verilate(simple_cpu SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tb/test_beach.sv
INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/rtl
TRACE
VERILATOR_ARGS --timescale 1ns/1ns
VERILATOR_ARGS
 +1364-1995ext+<ext>
 +1364-2001ext+<ext>        
 +1364-2005ext+<ext>        
 +1800-2005ext+<ext>        
 +1800-2009ext+<ext>        
 +1800-2012ext+<ext>
 +1800-2017ext+<ext>
-F ${CMAKE_CURRENT_SOURCE_DIR}/tb/test_beach.f
)