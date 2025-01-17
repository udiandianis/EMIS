#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H

#include "manager_ctrl.h"

class ManagerCtrlImpl : public ManagerCtrl {
public:
    void addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password) override;
    void deleteManager(std::vector<Manager>& managers, int managerId) override;
    void listAllManagers(const std::vector<Manager>& managers) override;
};

#endif // MANAGER_CTRL_IMPL_H
