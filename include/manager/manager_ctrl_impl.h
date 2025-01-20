#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H

#include "manager_ctrl.h"
#include "models/manager.h"
#include <vector>

class ManagerCtrlImpl : public ManagerCtrl {
private:
    std::vector<Manager> managers;

public:
    void addManager(const std::string& name, const std::string& password) override;
    void deleteManager(int id) override;
    std::vector<Manager> listManagers() const override;
    void saveManagersToFile(const std::string& filename) const override;
    void loadManagersFromFile(const std::string& filename) override;
};

#endif // MANAGER_CTRL_IMPL_H
