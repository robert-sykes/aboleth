cmake_minimum_required (VERSION 3.8)

project (aboleth C)

find_package(SDL2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable (aboleth 
	src/main.c
	src/cpu/cpu.c
	src/mem/memory.c
	src/rom/rom.c
)

target_include_directories(aboleth PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(aboleth ${SDL2_LIBRARIES})

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Zi /Od")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /DEBUG")

# Define the source directory and output directory for copying
set(SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/roms")
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/roms")

# Custom command to copy the directory after build
add_custom_command(TARGET aboleth POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SOURCE_DIRECTORY}
        ${OUTPUT_DIRECTORY}
    COMMENT "Copying roms to output directory"
)