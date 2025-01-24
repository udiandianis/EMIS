#pragma once

#include <string>

class ServiceCtrl {
public:
    virtual ~ServiceCtrl() = default;

    // 部门管理
    virtual int addDepartment(const std::string& name) = 0;
    virtual int delDepartment(int deptId) = 0;
    virtual int listDepartment() = 0;

    // 员工管理
    virtual int addEmployee(const std::string& name, bool isMale, int age, int deptId) = 0;
    virtual int delEmployee(int empId) = 0;
    virtual int modifyEmployee(int empId) = 0;
    virtual int listDeptEmployees(int deptId) = 0;
    virtual int listAllEmployees() = 0;
};
