#include "core/emis.h"
#include "manager/manager_ctrl_impl.h"
#include "manager/manager_mode_impl.h"
#include "service/service_ctrl_impl.h"
#include "service/service_mode_impl.h"
#include <iostream>

// 全局变量声明
ManagerCtrlImpl managerCtrl; // 管理员控制器
ServiceCtrlImpl serviceCtrl; // 服务控制器

// 主菜单显示
void displayMainMenu() {
    std::cout << "\n=== 企业管理系统 ===\n";
    std::cout << "1. 管理员管理\n";
    std::cout << "2. 部门与员工管理\n";
    std::cout << "3. 退出系统\n";
    std::cout << "请输入操作编号: ";
}

// 主程序入口
int main() {
    initializeSystem(); // 初始化系统，加载数据

    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            ManagerModeImpl managerMode(&managerCtrl);
            managerMode.displayMenu();
            managerMode.handleInput();
            break;
        }
        case 2: {
            ServiceModeImpl serviceMode(&serviceCtrl);
            serviceMode.displayMenu();
            serviceMode.handleInput();
            break;
        }
        case 3:
            std::cout << "\n正在保存系统数据...\n";
            saveData(); // 保存所有数据
            std::cout << "系统数据保存成功，程序即将退出...\n";
            return 0;
        default:
            std::cout << "无效操作，请重新输入。\n";
        }
    }

    return 0;
}
