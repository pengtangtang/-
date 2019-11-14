aux_source_directory(. SRC_LIST)

include_directories(../lib_testFunc)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(main ${SRC_LIST})

target_link_libraries(main testFunc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
