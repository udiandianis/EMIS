#include "manager_mode_impl.h"
#include <iostream>
#include <string>

ManagerModeImpl::ManagerModeImpl(ManagerCtrl* ctrl) : controller(ctrl) {}

void ManagerModeImpl::displayMenu() {
    std::cout << "\n=== 管理员管理系统 ===\n";
    std::cout << "1. 添加管理员\n";
    std::cout << "2. 删除管理员\n";
    std::cout << "3. 显示管理员列表\n";
    std::cout << "4. 返回主菜单\n";
    std::cout << "请输入操作编号: ";
}

void ManagerModeImpl::handleInput() {
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
        std::string username, password;
        std::cout << "请输入管理员用户名: ";
        std::cin >> username;
        std::cout << "请输入管理员密码: ";
        std::cin >> password;
        controller->addManager(username, password);
        break;
    }
    case 2: {
        int id;
        std::cout << "请输入要删除的管理员 ID: ";
        std::cin >> id;
        controller->deleteManager(id);
        break;
    }
    case 3: {
        auto managers = controller->listManagers();
        std::cout << "\n=== 管理员列表 ===\n";
        for (const auto& mgr : managers) {
            std::cout << "ID: " << mgr.getId() << "，用户名: " << mgr.getUsername() << "\n";
        }
        break;
    }
    case 4:
        std::cout << "返回主菜单\n";
        break;
    default:
        std::cout << "无效操作\n";
    }
}
