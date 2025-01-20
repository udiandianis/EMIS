#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"
#include "manager_ctrl.h"
#include "manager_view.h"

class ManagerModeImpl : public ManagerMode {
private:
    ManagerCtrl* controller;
    ManagerView* viewer;

public:
    ManagerModeImpl(ManagerCtrl* ctrl, ManagerView* view);
    void displayMenu() override;
    void handleInput() override;
};

#endif // MANAGER_MODE_IMPL_H
