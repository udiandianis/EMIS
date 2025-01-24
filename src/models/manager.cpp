#include "manager.h"

Manager::Manager(int id, const std::string& name, const std::string& password) : id_(id), name_(name), password_(password) {
}

int Manager::getId() const {
    return id_;
}

const std::string& Manager::getName() const {
    return name_;
}

const std::string& Manager::getPassword() const {
    return password_;
}

void Manager::setName(const std::string& name) {
    name_ = name;
}

void Manager::setPassword(const std::string& password) {
    password_ = password;
}
