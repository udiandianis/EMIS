#include "manager_view_impl.h"
#include <iostream>

ManagerViewImpl::ManagerViewImpl(ManagerCtrl* ctrl) : controller(ctrl) {}

void ManagerViewImpl::showManagerList() {
    auto managers = controller->listManagers();
    if (managers.empty()) {
        std::cout << "��ǰû���κι���Ա��\n";
    }
    else {
        std::cout << "\n=== ����Ա�б� ===\n";
        for (const auto& mgr : managers) {
            std::cout << "ID: " << mgr.getId()
                << "���û���: " << mgr.getUsername() << "\n";
        }
    }
}
