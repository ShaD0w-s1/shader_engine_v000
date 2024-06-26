
cmake_minimum_required(VERSION 3.20.0)
project(shader_engine VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_CMAKE_DIR ${CMAKE_SOURCE_DIR}/cmake)

find_package(Vulkan REQUIRED)

message(STATUS "Vulkan_INCLUDE_DIRS = ${Vulkan_INCLUDE_DIRS}")
message(STATUS "Vulkan_LIBRARIES = ${Vulkan_LIBRARIES}")


# 包含自定义命令文件
include(${PROJECT_CMAKE_DIR}/copy_compile_commands.cmake)
include(${PROJECT_CMAKE_DIR}/rebuild.cmake)

# 调用自定义函数
rebuild()
copy_compile_commands()

# 创建目标库
add_library(${PROJECT_NAME} SHARED src/main.cpp)

# 设置包含目录
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE 
        ${Vulkan_INCLUDE_DIRS}
)

# 链接库
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        ${Vulkan_LIBRARIES}
)

# 设置公共头文件
set_target_properties(${PROJECT_NAME} PROPERTIES
PUBLIC_HEADER "include/${PROJECT_NAME}.h"
)

# 设置输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# 安装规则
install(TARGETS ${PROJECT_NAME}
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
RUNTIME DESTINATION bin
PUBLIC_HEADER DESTINATION include
)


