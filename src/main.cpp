#include <iostream>
#include <vector>
#include "Manager.h"
#include "manager_ctrl_impl.h"
#include "manager_view_impl.h"
#include "manager_mode_impl.h"

int main()
{
    // 数据文件路径
    std::string filename = "managers.dat";

    // 创建控制器、视图、模式对象
    ManagerCtrlImpl ctrl;
    ManagerViewImpl view;
    ManagerModeImpl mode;

    // 存放管理员
    std::vector<Manager> managers;

    // 启动时先加载文件中的管理员数据
    ctrl.loadData(filename, managers);

    // 进入主循环
    mode.run(ctrl, view, managers);

    // 退出前保存到文件
    ctrl.saveData(filename, managers);

    std::cout << "程序已退出并保存数据到 " << filename << "。\n";
    return 0;
}
