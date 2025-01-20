#include "manager.h"

Manager::Manager(int id, const std::string& username, const std::string& password)
    : id(id), username(username), password(password) {}

int Manager::getId() const {
    return id;
}

std::string Manager::getUsername() const {
    return username;
}

std::string Manager::getPassword() const {
    return password;
}
