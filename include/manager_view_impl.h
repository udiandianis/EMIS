#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include <utility> // std::pair

/**
 * 视图实现类
 */
class ManagerViewImpl : public ManagerView {
public:
    // 显示所有管理员
    void displayManagerList(const std::vector<Manager>& managers) override;

    // 显示单个管理员详情
    void displayManagerDetails(const Manager& manager) override;

    // 提示并读取(用户名, 密码)
    // 返回 {username, password}
    std::pair<std::string, std::string> promptForManagerInput() override;
};

#endif // MANAGER_VIEW_IMPL_H
