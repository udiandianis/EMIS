#include "department.h"

Department::Department(int id, const std::string& name, int empCount) : id_(id), name_(name), empCount_(empCount) {
}

int Department::getId() const {
    return id_;
}

const std::string& Department::getName() const {
    return name_;
}

int Department::getEmpCount() const {
    return empCount_;
}

void Department::setName(const std::string& name) {
    name_ = name;
}

void Department::setEmpCount(int count) {
    empCount_ = count;
}
