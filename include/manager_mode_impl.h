#pragma once

#include <string>
#include <vector>

#include "manager.h"
#include "manager_mode.h"

class ManagerModeImpl : public ManagerMode {
public:
    ManagerModeImpl() = default;
    ~ManagerModeImpl() override = default;

    int init() override;
    int save() override;

    int addManager(const std::string& name, const std::string& password) override;
    int delManager(int managerId) override;
    int listManager() override;

private:
    std::vector<Manager> managers_;
};
