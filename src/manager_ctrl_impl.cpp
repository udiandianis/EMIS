#include "manager_ctrl_impl.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void ManagerCtrlImpl::addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password)
{
    int newId = managers.empty() ? 1001 : managers.back().getId() + 1;
    managers.emplace_back(newId, username, password);
    std::cout << "管理员 " << username << " 已成功添加，ID为 " << newId << "\n";
}

void ManagerCtrlImpl::deleteManager(std::vector<Manager>& managers, int managerId)
{
    auto it = std::remove_if(managers.begin(), managers.end(),
        [managerId](const Manager& m) {
            return m.getId() == managerId;
        });
    if (it != managers.end()) {
        managers.erase(it, managers.end());
        std::cout << "管理员 ID " << managerId << " 已删除。\n";
    }
    else {
        std::cout << "未找到管理员 ID " << managerId << "。\n";
    }
}

void ManagerCtrlImpl::listAllManagers(const std::vector<Manager>& managers)
{
    if (managers.empty()) {
        std::cout << "当前没有任何管理员。\n";
        return;
    }
    std::cout << "========== 管理员列表 ==========\n";
    for (const auto& mgr : managers) {
        std::cout << "ID: " << mgr.getId()
            << ", 用户名: " << mgr.getUsername()
            << ", 密码: " << mgr.getPassword() << "\n";
    }
}

void ManagerCtrlImpl::loadData(const std::string& filename, std::vector<Manager>& managers)
{
    managers.clear();
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "警告: 无法打开文件 " << filename << "（可能不存在），将不加载任何管理员。\n";
        return;
    }

    int id;
    std::string username, password;
    while (fin >> id >> username >> password) {
        managers.emplace_back(id, username, password);
    }

    fin.close();
    std::cout << "已从文件 " << filename << " 加载 " << managers.size() << " 个管理员。\n";
}

void ManagerCtrlImpl::saveData(const std::string& filename, const std::vector<Manager>& managers)
{
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "错误: 无法写入文件 " << filename << "。\n";
        return;
    }

    for (const auto& mgr : managers) {
        fout << mgr.getId() << " " << mgr.getUsername() << " " << mgr.getPassword() << "\n";
    }
    fout.close();
    std::cout << "已将 " << managers.size() << " 个管理员保存到文件 " << filename << "。\n";
}
