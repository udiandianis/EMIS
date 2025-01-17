#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H

#include <string>
#include <vector>
#include "Manager.h"

class ManagerCtrl {
public:
    virtual ~ManagerCtrl() = default;

    // 添加管理员
    virtual void addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password) = 0;

    // 删除管理员
    virtual void deleteManager(std::vector<Manager>& managers, int managerId) = 0;

    // 列出所有管理员
    virtual void listAllManagers(const std::vector<Manager>& managers) = 0;

    // 从文件加载
    virtual void loadData(const std::string& filename, std::vector<Manager>& managers) = 0;

    // 保存到文件
    virtual void saveData(const std::string& filename, const std::vector<Manager>& managers) = 0;
};

#endif // MANAGER_CTRL_H
