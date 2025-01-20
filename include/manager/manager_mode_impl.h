#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"
#include "manager_ctrl.h"

class ManagerModeImpl : public ManagerMode {
private:
    ManagerCtrl* controller;

public:
    explicit ManagerModeImpl(ManagerCtrl* ctrl);
    void displayMenu() override;
    void handleInput() override;
};

#endif // MANAGER_MODE_IMPL_H
