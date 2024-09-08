cmake_minimum_required(VERSION 3.12)

set(CORE_NAME Core)

#-------------------------#
#---All private sources---#
#-------------------------#
set(CORE_PRIVATE_SOURCES
	src/Application.cpp
	src/Rendering/OpenGL/OpenGL_Renderer.cpp
)

#-------------------------#
#---All public includes---#
#-------------------------#
set(CORE_PUBLIC_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
)

#--------------------------#
#---All private includes---#
#--------------------------#
set(CORE_PRIVATE_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
	src/Rendering/OpenGL/OpenGL_Renderer.hpp
)

#-----------------#
#---All sources---#
#-----------------#
set(CORE_ALL_FILES
	${CORE_PRIVATE_SOURCES}
	${CORE_PUBLIC_INCLUDES}
	${CORE_PRIVATE_INCLUDES}
)

#-------------------------------#
#---Add static library "Core"---#
#-------------------------------#
add_library(${CORE_NAME} STATIC
	${CORE_ALL_FILES}
)


#--------------------------#
#---Add "spdlog" library---#
#--------------------------#
add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${CORE_NAME} PRIVATE spdlog)

#------------------------#
#---Add "glad" library---#
#------------------------#
add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${CORE_NAME} PRIVATE glad)

#------------------------#
#---Add "glfw" library---#
#------------------------#
add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${CORE_NAME} PRIVATE glfw)


#------------------------------------------#
#---View of the file system on VS editor---#
#------------------------------------------#
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${CORE_ALL_FILES}
)

#------------------------#
#--Compilation options---#
#------------------------#
target_include_directories(${CORE_NAME} PUBLIC includes)
target_include_directories(${CORE_NAME} PRIVATE src)
target_compile_features(${CORE_NAME} PUBLIC cxx_std_17)