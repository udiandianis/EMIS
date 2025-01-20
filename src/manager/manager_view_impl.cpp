#include "manager_view_impl.h"
#include <iostream>

ManagerViewImpl::ManagerViewImpl(ManagerCtrl* ctrl) : controller(ctrl) {}

void ManagerViewImpl::showManagerList() {
    auto managers = controller->listManagers();
    if (managers.empty()) {
        std::cout << "当前没有任何管理员。\n";
    }
    else {
        std::cout << "\n=== 管理员列表 ===\n";
        for (const auto& mgr : managers) {
            std::cout << "ID: " << mgr.getId()
                << "，用户名: " << mgr.getUsername() << "\n";
        }
    }
}
