#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include "manager_ctrl.h"
#include "manager_view.h"

class ManagerMode {
public:
    virtual void run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers) = 0;
    virtual ~ManagerMode() {}
};

#endif // MANAGER_MODE_H
