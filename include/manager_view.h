#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include <vector>
#include <string>
#include "Manager.h"

/**
 * 抽象视图接口，定义显示管理员列表、管理员详情，以及提示输入的方法
 */
class ManagerView {
public:
    virtual ~ManagerView() = default;

    // 显示所有管理员
    virtual void displayManagerList(const std::vector<Manager>& managers) = 0;

    // 显示单个管理员信息
    virtual void displayManagerDetails(const Manager& manager) = 0;

    // 提示并读取(用户名, 密码)
    // 建议返回 pair<string, string>: {username, password}
    virtual std::pair<std::string, std::string> promptForManagerInput() = 0;
};

#endif // MANAGER_VIEW_H
