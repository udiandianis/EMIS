#include "manager_view_impl.h"
#include <iostream>

ManagerViewImpl::ManagerViewImpl(ManagerCtrl* ctrl) : controller(ctrl) {}

void ManagerViewImpl::showManagerList() {
    const auto& managers = controller->listManagers();
    if (managers.empty()) {
        std::cout << "当前没有任何管理员。\n";
        return;
    }

    std::cout << "=== 管理员列表 ===\n";
    for (const auto& manager : managers) {
        std::cout << "ID: " << manager.getId()
            << ", 用户名: " << manager.getUsername()
            << ", 密码: " << manager.getPassword() << "\n";
    }
}
