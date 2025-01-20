# CMake 最低版本要求
cmake_minimum_required(VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# 项目信息
project("EMIS")

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

# 源文件分组
set(CORE_SRC
    src/core/emis.cpp
    src/core/tools.cpp
)

set(MODEL_SRC
    src/models/manager.cpp
    src/models/department.cpp
    src/models/employee.cpp
)

set(MANAGER_SRC
    src/manager/manager_ctrl_impl.cpp
    src/manager/manager_mode_impl.cpp
    src/manager/manager_view_impl.cpp
)

set(SERVICE_SRC
    src/service/service_ctrl_impl.cpp
    src/service/service_mode_impl.cpp
    src/service/service_view_impl.cpp
)

# 添加可执行文件
add_executable(EMIS
    src/main.cpp
    ${CORE_SRC}
    ${MODEL_SRC}
    ${MANAGER_SRC}
    ${SERVICE_SRC}
)

# 设置包含头文件目录
target_include_directories(EMIS PUBLIC
    ${PROJECT_SOURCE_DIR}/include        # 根 include 目录
    ${PROJECT_SOURCE_DIR}/include/core  # 核心头文件目录
    ${PROJECT_SOURCE_DIR}/include/models # 模型头文件目录
    ${PROJECT_SOURCE_DIR}/include/manager # 管理模块头文件目录
    ${PROJECT_SOURCE_DIR}/include/service # 服务模块头文件目录
)

# 将数据文件复制到运行时目录
file(GLOB DATA_FILES ${PROJECT_SOURCE_DIR}/data/*)
foreach(DATA_FILE ${DATA_FILES})
    get_filename_component(FILENAME ${DATA_FILE} NAME)
    configure_file(${DATA_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${FILENAME} COPYONLY)
    configure_file(${DATA_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/${FILENAME} COPYONLY)
    configure_file(${DATA_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/${FILENAME} COPYONLY)
endforeach()

# 输出构建信息
message(STATUS "Source directory: ${PROJECT_SOURCE_DIR}")
message(STATUS "Binary directory: ${CMAKE_BINARY_DIR}")
message(STATUS "Runtime directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
