#include "department.h"

Department::Department(int id, const std::string& name) : id(id), name(name) {}

int Department::getId() const {
    return id;
}

std::string Department::getName() const {
    return name;
}

void Department::setName(const std::string& newName) {
    name = newName;
}
