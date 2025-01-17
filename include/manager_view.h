#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include <vector>
#include "Manager.h"

class ManagerView {
public:
    virtual void displayManagerList(const std::vector<Manager>& managers) = 0;
    virtual void displayManagerDetails(const Manager& manager) = 0;
    virtual std::pair<std::string, std::string> promptForManagerInput() = 0;
    virtual ~ManagerView() {}
};

#endif // MANAGER_VIEW_H
