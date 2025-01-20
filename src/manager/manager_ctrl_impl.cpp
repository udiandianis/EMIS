#include "manager_ctrl_impl.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "tools.h"
#include "emis.h"

void ManagerCtrlImpl::addManager(const std::string& name, const std::string& password) {
    int newId = generateUniqueID(ID_FILE);
    managers.emplace_back(newId, name, password);
    std::cout << "管理员添加成功，ID: " << newId << "，用户名: " << name << "\n";
}

void ManagerCtrlImpl::deleteManager(int id) {
    auto it = std::remove_if(managers.begin(), managers.end(),
        [id](const Manager& m) { return m.getId() == id; });
    if (it != managers.end()) {
        managers.erase(it, managers.end());
        std::cout << "管理员删除成功，ID: " << id << "\n";
    }
    else {
        std::cout << "未找到管理员 ID: " << id << "\n";
    }
}

std::vector<Manager> ManagerCtrlImpl::listManagers() const {
    return managers;
}

void ManagerCtrlImpl::saveManagersToFile(const char* filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "无法打开文件保存管理员数据！\n";
        return;
    }

    for (const auto& manager : managers) {
        file << manager.getId() << " "
            << manager.getUsername() << " "
            << manager.getPassword() << "\n";
    }
    file.close();
    std::cout << "管理员数据已保存。\n";
}

void ManagerCtrlImpl::loadManagersFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "无法打开文件加载管理员数据！\n";
        return;
    }

    managers.clear();
    int id;
    std::string username, password;

    while (file >> id >> username >> password) {
        managers.emplace_back(id, username, password);
    }
    file.close();
    std::cout << "已加载 " << managers.size() << " 个管理员。\n";
}
