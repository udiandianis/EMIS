#include "employee.h"

Employee::Employee(int id, const std::string& name, bool isMale, int age, int deptId) : id_(id), name_(name), isMale_(isMale), age_(age), deptId_(deptId) {
}

int Employee::getId() const {
    return id_;
}

const std::string& Employee::getName() const {
    return name_;
}

bool Employee::isMale() const {
    return isMale_;
}

int Employee::getAge() const {
    return age_;
}

int Employee::getDeptId() const {
    return deptId_;
}

void Employee::setName(const std::string& name) {
    name_ = name;
}

void Employee::setIsMale(bool isMale) {
    isMale_ = isMale;
}

void Employee::setAge(int age) {
    age_ = age;
}

void Employee::setDeptId(int deptId) {
    deptId_ = deptId;
}
