
cmake_minimum_required(VERSION 3.20.0)
project(shader_enginer VERSION 0.0.1 DESCRIPTION cmake HOMEPAGE_URL NONE LANGUAGES CXX)

set(CXX_STANDARD_REQUIRED 17)
set(CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

add_executable(${PROJECT_NAME} src/main.cpp)
message(${PROJECT_BINARY_DIR})

find_package(Vulkan REQUIRED)
if(VULKAN_FOUND)
    message("-- Vulkan version is " ${Vulkan_VERSION})
    include_directories(${Vulkan_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Could not find Vulkan library")
endif()



find_package(glfw3 REQUIRED)
if(glfw3_FOUND)
    message("-- GLFW3 version is " ${glfw3_VERSION})
    target_link_libraries(${PROJECT_NAME} glfw)
else()
    message(FATAL_ERROR "Could not find GLFW3 library")
endif()

# find_package(glm REQUIRED)
# if(glm_FOUND)
#     message("-- GLM version is " ${glm_VERSION})
#     target_link_libraries(${PROJECT_NAME} glm)
# else()
#     message(FATAL_ERROR "Could not find GLM library")
# endif()
    


