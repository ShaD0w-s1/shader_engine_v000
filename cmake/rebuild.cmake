# 重建目标
function(rebuild)
    add_custom_target(rebuild
        COMMAND ${CMAKE_COMMAND} -E echo "Cleaning build directory"
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR} || ${CMAKE_COMMAND} -E echo "Directory does not exist, skipping removal"
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} 
            -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
            -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -G "${CMAKE_GENERATOR}"
            ${CMAKE_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endfunction()