#include "manager_mode_impl.h"
#include <iostream>
#include <string>

ManagerModeImpl::ManagerModeImpl(ManagerCtrl* ctrl, ManagerView* view)
    : controller(ctrl), viewer(view) {}

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

    do {
        std::cin >> choice;
        std::cin.ignore(); // 清除缓冲区
        switch (choice) {
        case 1: {
            std::string username, password;
            std::cout << "请输入管理员用户名: ";
            std::getline(std::cin, username);
            std::cout << "请输入管理员密码: ";
            std::getline(std::cin, password);
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
            viewer->showManagerList();
            break;
        }
        case 4:
            std::cout << "正在返回主菜单。\n";
            return;
        default:
            std::cout << "无效操作\n";
        }
        displayMenu();
    } while(true);
}
