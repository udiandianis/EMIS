#include "manager_ctrl_impl.h"
#include "manager_mode.h"

ManagerCtrlImpl::ManagerCtrlImpl(ManagerMode& mode) : mode_(mode) {
}

int ManagerCtrlImpl::addManager(const std::string& name, const std::string& password) {
    return mode_.addManager(name, password);
}

int ManagerCtrlImpl::delManager(int managerId) {
    return mode_.delManager(managerId);
}

int ManagerCtrlImpl::listManager() {
    return mode_.listManager();
}
