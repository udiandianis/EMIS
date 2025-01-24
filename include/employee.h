#pragma once

#include <string>

class Employee {
public:
    Employee() = default;
    Employee(int id, const std::string& name, bool isMale, int age, int deptId);

    int getId() const;
    const std::string& getName() const;
    bool isMale() const;
    int getAge() const;
    int getDeptId() const;

    void setName(const std::string& name);
    void setIsMale(bool isMale);
    void setAge(int age);
    void setDeptId(int deptId);

private:
    int id_{ 0 };
    std::string name_;
    bool isMale_{ true };
    int age_{ 0 };
    int deptId_{ 0 };
};
