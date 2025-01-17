#include "manager_view_impl.h"
#include <iostream>

void ManagerViewImpl::displayManagerList(const std::vector<Manager>& managers) {
    for (const auto& manager : managers) {
        std::cout << "ID: " << manager.id << ", 用户名: " << manager.username << std::endl;
    }
}

void ManagerViewImpl::displayManagerDetails(const Manager& manager) {
    std::cout << "管理员ID: " << manager.id << ", 用户名: " << manager.username << ", 密码: " << manager.password << std::endl;
}

std::pair<std::string, std::string> ManagerViewImpl::promptForManagerInput() {
    std::pair<std::string, std::string> result;
    std::cout << "请输入管理员的用户名: ";
    std::cin >> result.first;   // 用户名
    std::cout << "请输入管理员的密码: ";
    std::cin >> result.second;  // 密码
    return result;
}
