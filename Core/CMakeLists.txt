cmake_minimum_required(VERSION 3.12)

set(CORE_NAME Core)

set(CORE_ALL_SRC
	src/test.cpp
)

add_library(${CORE_NAME} STATIC
	${CORE_ALL_SRC}
)

#---View of the file system on VS---
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${CORE_ALL_SRC}
)

#--Compilation options---
target_include_directories(${CORE_NAME} PUBLIC includes)
target_include_directories(${CORE_NAME} PRIVATE src)
target_compile_features(${CORE_NAME} PUBLIC cxx_std_17)