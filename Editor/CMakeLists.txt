cmake_minimum_required(VERSION 3.12)

set(EDITOR_NAME Editor)

add_executable(${EDITOR_NAME} 
	src/main.cpp
)

target_link_libraries(${EDITOR_NAME}
	Core
)
target_compile_features(${EDITOR_NAME} PUBLIC cxx_std_17)
set_target_properties(${EDITOR_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_Dir}/bin)