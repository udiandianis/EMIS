#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int id;
    std::string name;
    char gender;
    int age;
    int departmentId;

public:
    Employee(int id, const std::string& name, char gender, int age, int departmentId);
    int getId() const;
    std::string getName() const;
    char getGender() const;
    int getAge() const;
    int getDepartmentId() const;
    void setName(const std::string& newName);
    void setGender(char newGender);
    void setAge(int newAge);
    void setDepartmentId(int newDepartmentId);
};

#endif // EMPLOYEE_H
