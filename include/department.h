#pragma once

#include <string>

class Department {
public:
    Department() = default;
    Department(int id, const std::string& name, int empCount);

    int getId() const;
    const std::string& getName() const;
    int getEmpCount() const;

    void setName(const std::string& name);
    void setEmpCount(int count);

private:
    int id_{ 0 };
    std::string name_;
    int empCount_{ 0 };
};
