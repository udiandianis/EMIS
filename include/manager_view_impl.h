#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include <utility>    // std::pair
#include <string>

/**
 * ManagerViewImpl 是 ManagerView 的具体实现类。
 * 其中 promptForManagerInput() 将先后提示并读取用户名、密码，
 * 并返回一个 {username, password} 的二元组。
 */
class ManagerViewImpl : public ManagerView {
public:
    // 显示所有管理员列表
    void displayManagerList(const std::vector<Manager>& managers) override;

    // 显示单个管理员详情
    void displayManagerDetails(const Manager& manager) override;

    // 修改：返回一个 pair<string, string>，分别是 (username, password)
    std::pair<std::string, std::string> promptForManagerInput() override;
};

#endif // MANAGER_VIEW_IMPL_H
