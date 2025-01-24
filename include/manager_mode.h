#pragma once

#include <string>

class ManagerMode {
public:
    virtual ~ManagerMode() = default;

    // 初始化
    virtual int init() = 0;
    // 保存数据
    virtual int save() = 0;

    // 业务操作
    virtual int addManager(const std::string& name, const std::string& password) = 0;
    virtual int delManager(int managerId) = 0;
    virtual int listManager() = 0;
};
