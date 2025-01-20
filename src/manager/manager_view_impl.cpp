#include "manager_view_impl.h"
#include <iostream>

ManagerViewImpl::ManagerViewImpl(ManagerCtrl* ctrl) : controller(ctrl) {}

void ManagerViewImpl::showManagerList() {
    const auto& managers = controller->listManagers();
    if (managers.empty()) {
        std::cout << "��ǰû���κι���Ա��\n";
        return;
    }

    std::cout << "=== ����Ա�б� ===\n";
    for (const auto& manager : managers) {
        std::cout << "ID: " << manager.getId()
            << ", �û���: " << manager.getUsername()
            << ", ����: " << manager.getPassword() << "\n";
    }
}
