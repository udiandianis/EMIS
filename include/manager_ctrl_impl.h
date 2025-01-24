#pragma once

#include "manager_ctrl.h"

class ManagerMode;

class ManagerCtrlImpl : public ManagerCtrl {
public:
    explicit ManagerCtrlImpl(ManagerMode& mode);
    ~ManagerCtrlImpl() override = default;

    int addManager(const std::string& name, const std::string& password) override;
    int delManager(int managerId) override;
    int listManager() override;

private:
    ManagerMode& mode_;
};
