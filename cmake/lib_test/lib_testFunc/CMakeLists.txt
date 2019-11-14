aux_source_directory(. SRC_LIST)
#将当前目录的源文件列表保存在变量中

add_library(testFunc_shared SHARED ${SRC_LIST})
add_library(testFunc_static STATIC ${SRC_LIST})
#生成动态库或动态库（参数1：指定库的名字，参数2：决定是动态库还是静态库，参数3：指定生成库的源文件）

set_target_properties(testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties(testFunc_static PROPERTIES OUTPUT_NAME "testFunc")
#设置库的输出名字等其他功能

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#设置库文件的默认输出路径
