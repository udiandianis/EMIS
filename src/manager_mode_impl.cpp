#include "manager_mode_impl.h"
#include <iostream>

void ManagerModeImpl::run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers)
{
    while (true) {
        std::cout << "\n===== 管理员管理 =====\n"
            << "1. 添加管理员\n"
            << "2. 删除管理员\n"
            << "3. 列出所有管理员\n"
            << "4. 退出\n"
            << "请输入选项: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // 从视图层读取用户名、密码
            auto [username, password] = view.promptForManagerInput();
            // 调用控制器添加
            ctrl.addManager(managers, username, password);
        }
        else if (choice == 2) {
            std::cout << "请输入要删除的管理员ID: ";
            int managerId;
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
            std::cout << "无效选项，请重新输入。\n";
        }
    }
}
