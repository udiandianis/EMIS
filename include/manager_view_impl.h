#pragma once

#include "manager_view.h"

class ManagerViewImpl : public ManagerView {
public:
    ManagerViewImpl() = default;
    ~ManagerViewImpl() override = default;

    void menu() override;
    void setManagerCtrl(ManagerCtrl* ctrl) override;

private:
    ManagerCtrl* ctrl_{ nullptr };
};
