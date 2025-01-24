cmake_minimum_required(VERSION 3.15)
project(emis LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 工具模块
add_library(tools
    tools/tools.cpp
)

# 模型模块
add_library(models
    src/models/department.cpp
    src/models/employee.cpp
    src/models/manager.cpp
    src/models/emis.cpp
)

# 管理子系统
add_library(manager
    src/manager/manager_ctrl_impl.cpp
    src/manager/manager_mode_impl.cpp
    src/manager/manager_view_impl.cpp
)

# 业务子系统
add_library(service
    src/service/service_ctrl_impl.cpp
    src/service/service_mode_impl.cpp
    src/service/service_view_impl.cpp
)

# 主程序
add_executable(emis_main
    src/main.cpp
)

# 链接依赖
target_link_libraries(emis_main
    PRIVATE
    tools
    models
    manager
    service
)

# 安装目标（可选）
install(TARGETS emis_main DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)