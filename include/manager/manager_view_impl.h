#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include "manager_ctrl.h"

class ManagerViewImpl : public ManagerView {
private:
    ManagerCtrl* controller;

public:
    explicit ManagerViewImpl(ManagerCtrl* ctrl);
    void showManagerList() override;
};

#endif // MANAGER_VIEW_IMPL_H
