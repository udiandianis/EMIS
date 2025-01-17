#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H

#include <vector>
#include "Manager.h"

class ManagerCtrl {
public:
    virtual void addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password) = 0;
    virtual void deleteManager(std::vector<Manager>& managers, int managerId) = 0;
    virtual void listAllManagers(const std::vector<Manager>& managers) = 0;
    virtual ~ManagerCtrl() {}
};

#endif // MANAGER_CTRL_H
