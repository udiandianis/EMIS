#include "manager_ctrl_impl.h"
#include <iostream>

void ManagerCtrlImpl::addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password) {
    int newId = managers.empty() ? 1001 : managers.back().id + 1;
    Manager newManager(newId, username, password);
    managers.push_back(newManager);
    std::cout << "管理员 " << username << " 已成功添加，ID为 " << newId << std::endl << std::endl;
}

void ManagerCtrlImpl::deleteManager(std::vector<Manager>& managers, int managerId) {
    auto it = std::remove_if(managers.begin(), managers.end(), [managerId](const Manager& m) {
        return m.id == managerId;
        });

    if (it != managers.end()) {
        managers.erase(it, managers.end());
        std::cout << "管理员 ID " << managerId << " 已删除。" << std::endl;
    }
    else {
        std::cout << "未找到 ID " << managerId << " 的管理员。" << std::endl;
    }
}

void ManagerCtrlImpl::listAllManagers(const std::vector<Manager>& managers) {
    std::cout << "管理员列表：" << std::endl;
    for (const auto& manager : managers) {
        std::cout << "ID: " << manager.id << ", 用户名: " << manager.username << std::endl;
    }
    std::cout << std::endl;
}
