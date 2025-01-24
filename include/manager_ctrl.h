#pragma once

#include <string>

class ManagerCtrl {
public:
    virtual ~ManagerCtrl() = default;

    // 添加管理员
    virtual int addManager(const std::string& name, const std::string& password) = 0;
    // 删除管理员
    virtual int delManager(int managerId) = 0;
    // 列出所有管理员
    virtual int listManager() = 0;
};
