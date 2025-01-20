#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include <vector>

class ServiceCtrlImpl : public ServiceCtrl {
private:
    std::vector<Department> departments;
    std::vector<Employee> employees;

public:
    void addDepartment(const std::string& name) override;
    void deleteDepartment(int id) override;
    std::vector<Department> listDepartments() const override;

    void addEmployee(const std::string& name, char gender, int age, int departmentId) override;
    void deleteEmployee(int id) override;
    std::vector<Employee> listEmployees(int departmentId) const override;

    void saveServiceDataToFile(const std::string& filename) const override;
    void loadServiceDataFromFile(const std::string& filename) override;
};

#endif // SERVICE_CTRL_IMPL_H
