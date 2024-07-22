cmake_minimum_required (VERSION 3.8)

project (aboleth C)

find_package(SDL2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable (aboleth 
	src/main.c
	src/cpu/cpu.c
	src/mem/memory.c
)

target_include_directories(aboleth PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(aboleth ${SDL2_LIBRARIES})

