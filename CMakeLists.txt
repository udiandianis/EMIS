# CMakeList.txt: EMIS 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("EMIS")

# 将源文件添加到可执行文件
add_executable(EMIS
    src/main.cpp
    src/manager_ctrl_impl.cpp
    src/manager_mode_impl.cpp
    src/manager_view_impl.cpp
)

# 包含头文件目录
target_include_directories(EMIS PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 复制数据文件到构建输出目录（保证可以读写）
configure_file(data/managers.dat ${CMAKE_BINARY_DIR}/managers.dat COPYONLY)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EMIS PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
