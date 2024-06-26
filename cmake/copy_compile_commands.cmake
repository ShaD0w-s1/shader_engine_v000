# 复制 compile_commands
function(copy_compile_commands)
    set(CMAKE_COMPILE_COMMANDS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_BINARY_DIR}/compile_commands.json
        COMMENT "Copying compile_commands.json to build directory"
    )
endfunction()