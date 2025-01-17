#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"

class ManagerModeImpl : public ManagerMode {
public:
    void run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers) override;
};

#endif // MANAGER_MODE_IMPL_H
