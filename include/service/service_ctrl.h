#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include <vector>
#include "models/department.h"
#include "models/employee.h"

class ServiceCtrl {
public:
    virtual void addDepartment(const std::string& name) = 0;
    virtual void deleteDepartment(int id) = 0;
    virtual std::vector<Department> listDepartments() const = 0;

    virtual void addEmployee(const std::string& name, char gender, int age, int departmentId) = 0;
    virtual void deleteEmployee(int id) = 0;
    virtual std::vector<Employee> listEmployees(int departmentId) const = 0;

    virtual void saveServiceDataToFile(const char* filename) const = 0;
    virtual void loadServiceDataFromFile(const char* filename) = 0;

    virtual ~ServiceCtrl() = default;
};

#endif // SERVICE_CTRL_H
