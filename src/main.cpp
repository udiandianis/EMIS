#include <iostream>
#include <vector>
#include "manager_mode_impl.h"
#include "manager_ctrl_impl.h"
#include "manager_view_impl.h"
#include "Manager.h"

int main() {
    std::vector<Manager> managers;
    ManagerViewImpl view;
    ManagerCtrlImpl ctrl;
    ManagerModeImpl mode;

    mode.run(ctrl, view, managers);

    return 0;
}
