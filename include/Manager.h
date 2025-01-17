#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class Manager {
public:
    int id;
    std::string username;
    std::string password;

    Manager(int id, const std::string& username, const std::string& password)
        : id(id), username(username), password(password) {}
};

#endif // MANAGER_H
