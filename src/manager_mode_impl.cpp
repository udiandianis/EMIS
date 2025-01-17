#include "manager_mode_impl.h"
#include <iostream>

void ManagerModeImpl::run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers) {
    int choice;
    while (true) {
        std::cout << "1. 添加管理员\n2. 删除管理员\n3. 列出所有管理员\n4. 退出\n请输入选项：";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {
            auto [username, password] = view.promptForManagerInput();
            ctrl.addManager(managers, username, password);
        }
        else if (choice == 2) {
            int managerId;
            std::cout << "请输入要删除的管理员ID: ";
            std::cin >> managerId;
            ctrl.deleteManager(managers, managerId);
        }
        else if (choice == 3) {
            ctrl.listAllManagers(managers);
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "无效选项，请重新输入。" << std::endl;
        }
    }
}
