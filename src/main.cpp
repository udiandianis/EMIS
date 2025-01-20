#include <iostream>
#include "core/emis.h"
#include "manager/manager_ctrl_impl.h"
#include "manager/manager_mode_impl.h"
#include "manager/manager_view_impl.h"
#include "service/service_ctrl_impl.h"
#include "service/service_mode_impl.h"
#include "service/service_view_impl.h"

// 全局控制器实例
ManagerCtrlImpl managerCtrl;
ServiceCtrlImpl serviceCtrl;

int main() {
    // 初始化系统
    initializeSystem();

    // 创建视图和模式
    ManagerViewImpl managerView(&managerCtrl);
    ManagerModeImpl managerMode(&managerCtrl, &managerView);

    ServiceViewImpl serviceView(&serviceCtrl);
    ServiceModeImpl serviceMode(&serviceCtrl, &serviceView);

    int choice;
    do {
        // 主菜单
        std::cout << "\n=== 企业管理系统 ===\n";
        std::cout << "1. 管理员管理\n";
        std::cout << "2. 企业服务管理\n";
        std::cout << "3. 退出系统\n";
        std::cout << "请输入操作编号: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            managerMode.displayMenu();
            managerMode.handleInput();
            break;
        case 2:
            serviceMode.displayMenu();
            serviceMode.handleInput();
            break;
        case 3:
            std::cout << "\n";
            saveData();
            std::cout << "已退出系统。\n";
            break;
        default:
            std::cout << "无效操作，请重新输入。\n";
        }
    } while (choice != 3);

    return 0;
}
