#include "models/employee.h"

// ���캯������ʼ��Ա����Ϣ
Employee::Employee(int id, const std::string& name, char gender, int age, int departmentId)
    : id(id), name(name), gender(gender), age(age), departmentId(departmentId) {}

// ��ȡԱ��ID
int Employee::getId() const {
    return id;
}

// ��ȡԱ������
std::string Employee::getName() const {
    return name;
}

// ��ȡԱ���Ա�
char Employee::getGender() const {
    return gender;
}

// ��ȡԱ������
int Employee::getAge() const {
    return age;
}

// ��ȡ��������ID
int Employee::getDepartmentId() const {
    return departmentId;
}

// ����Ա������
void Employee::setName(const std::string& newName) {
    name = newName;
}

// ����Ա���Ա�
void Employee::setGender(char newGender) {
    gender = newGender;
}

// ����Ա������
void Employee::setAge(int newAge) {
    age = newAge;
}

// ������������ID
void Employee::setDepartmentId(int newDepartmentId) {
    departmentId = newDepartmentId;
}
