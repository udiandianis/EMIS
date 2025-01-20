#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H

#include <string>
#include <vector>
#include "models/manager.h"

class ManagerCtrl {
public:
    virtual void addManager(const std::string& name, const std::string& password) = 0;
    virtual void deleteManager(int id) = 0;
    virtual std::vector<Manager> listManagers() const = 0;
    virtual void saveManagersToFile(const std::string& filename) const = 0;
    virtual void loadManagersFromFile(const std::string& filename) = 0;
    virtual ~ManagerCtrl() = default;
};

#endif // MANAGER_CTRL_H
