#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>

class Department {
private:
    int id;
    std::string name;

public:
    Department(int id, const std::string& name);
    int getId() const;
    std::string getName() const;
    void setName(const std::string& newName);
};

#endif // DEPARTMENT_H
