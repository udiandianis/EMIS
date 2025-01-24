#include <iostream>
#include <string>

#include "manager_ctrl.h"
#include "manager_view_impl.h"

void ManagerViewImpl::setManagerCtrl(ManagerCtrl* ctrl) {
    ctrl_ = ctrl;
}

void ManagerViewImpl::menu() {
    if (!ctrl_) {
        std::cout << "[Error] 未绑定 ManagerCtrl.\n";
        return;
    }

    bool running = true;
    while (running) {
        std::cout << "\n=== 管理子系统菜单 ===\n"
            << "1. 添加管理员\n"
            << "2. 删除管理员\n"
            << "3. 列出所有管理员\n"
            << "0. 返回上级菜单\n"
            << "======================\n"
            << "请选择: ";

        int choice = 0;
        std::cin >> choice;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            std::string name, pwd;
            std::cout << "请输入管理员用户名: ";
            std::cin >> name;
            std::cout << "请输入管理员密码: ";
            std::cin >> pwd;
            ctrl_->addManager(name, pwd);
            break;
        }
        case 2: {
            int id = 0;
            std::cout << "请输入要删除的管理员ID: ";
            std::cin >> id;
            ctrl_->delManager(id);
            break;
        }
        case 3:
            ctrl_->listManager();
            break;
        case 0:
            running = false;
            break;
        default:
            std::cout << "无效选项.\n";
            break;
        }
    }
}
