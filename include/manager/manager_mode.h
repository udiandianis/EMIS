#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

class ManagerMode {
public:
    virtual void displayMenu() = 0;
    virtual void handleInput() = 0;
    virtual ~ManagerMode() = default;
};

#endif // MANAGER_MODE_H
