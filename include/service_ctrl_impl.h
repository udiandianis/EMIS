#pragma once

#include "service_ctrl.h"

class ServiceMode;

class ServiceCtrlImpl : public ServiceCtrl {
public:
    explicit ServiceCtrlImpl(ServiceMode& mode);
    ~ServiceCtrlImpl() override = default;

    int addDepartment(const std::string& name) override;
    int delDepartment(int deptId) override;
    int listDepartment() override;

    int addEmployee(const std::string& name, bool isMale, int age, int deptId) override;
    int delEmployee(int empId) override;
    int modifyEmployee(int empId) override;
    int listDeptEmployees(int deptId) override;
    int listAllEmployees() override;

private:
    ServiceMode& mode_;
};
