#include "manager_view_impl.h"
#include <iostream>

// 显示所有管理员（仅简单示例）
void ManagerViewImpl::displayManagerList(const std::vector<Manager>& managers) {
    for (const auto& mgr : managers) {
        std::cout << "ID: " << mgr.getId()
            << ", 用户名: " << mgr.getUsername()
            << ", 密码: " << mgr.getPassword() << "\n";
    }
}

// 显示单个管理员详情
void ManagerViewImpl::displayManagerDetails(const Manager& manager) {
    std::cout << "管理员ID: " << manager.getId()
        << ", 用户名: " << manager.getUsername()
        << ", 密码: " << manager.getPassword() << "\n";
}

// 读取用户名、密码并返回
std::pair<std::string, std::string> ManagerViewImpl::promptForManagerInput() {
    std::string username, password;
    std::cout << "请输入管理员的用户名: ";
    std::cin >> username;
    std::cout << "请输入管理员的密码: ";
    std::cin >> password;
    return { username, password };
}
