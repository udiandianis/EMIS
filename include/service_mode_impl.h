#pragma once

#include <vector>

#include "department.h"
#include "employee.h"
#include "service_mode.h"

class ServiceModeImpl : public ServiceMode {
public:
    ServiceModeImpl() = default;
    ~ServiceModeImpl() override = default;

    int init() override;
    int save() override;

    int addDepartment(const std::string& name) override;
    int delDepartment(int deptId) override;
    int listDepartment() override;

    int addEmployee(const std::string& name, bool isMale, int age, int deptId) override;
    int delEmployee(int empId) override;
    int modifyEmployee(int empId) override;
    int listDeptEmployees(int deptId) override;
    int listAllEmployees() override;

private:
    std::vector<Department> departments_;
    std::vector<Employee> employees_;
};
