#include "models/employee.h"

// 构造函数，初始化员工信息
Employee::Employee(int id, const std::string& name, char gender, int age, int departmentId)
    : id(id), name(name), gender(gender), age(age), departmentId(departmentId) {}

// 获取员工ID
int Employee::getId() const {
    return id;
}

// 获取员工名称
std::string Employee::getName() const {
    return name;
}

// 获取员工性别
char Employee::getGender() const {
    return gender;
}

// 获取员工年龄
int Employee::getAge() const {
    return age;
}

// 获取所属部门ID
int Employee::getDepartmentId() const {
    return departmentId;
}

// 设置员工名称
void Employee::setName(const std::string& newName) {
    name = newName;
}

// 设置员工性别
void Employee::setGender(char newGender) {
    gender = newGender;
}

// 设置员工年龄
void Employee::setAge(int newAge) {
    age = newAge;
}

// 设置所属部门ID
void Employee::setDepartmentId(int newDepartmentId) {
    departmentId = newDepartmentId;
}
