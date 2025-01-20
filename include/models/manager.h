#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class Manager {
private:
    int id;
    std::string username;
    std::string password;

public:
    Manager(int id, const std::string& username, const std::string& password);
    int getId() const;
    std::string getUsername() const;
    std::string getPassword() const;
};

#endif // MANAGER_H
