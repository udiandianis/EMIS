#include "service_ctrl_impl.h"
#include "service_mode.h"

ServiceCtrlImpl::ServiceCtrlImpl(ServiceMode& mode) : mode_(mode) {
}

int ServiceCtrlImpl::addDepartment(const std::string& name) {
    return mode_.addDepartment(name);
}

int ServiceCtrlImpl::delDepartment(int deptId) {
    return mode_.delDepartment(deptId);
}

int ServiceCtrlImpl::listDepartment() {
    return mode_.listDepartment();
}

int ServiceCtrlImpl::addEmployee(const std::string& name, bool isMale, int age, int deptId) {
    return mode_.addEmployee(name, isMale, age, deptId);
}

int ServiceCtrlImpl::delEmployee(int empId) {
    return mode_.delEmployee(empId);
}

int ServiceCtrlImpl::modifyEmployee(int empId) {
    return mode_.modifyEmployee(empId);
}

int ServiceCtrlImpl::listDeptEmployees(int deptId) {
    return mode_.listDeptEmployees(deptId);
}

int ServiceCtrlImpl::listAllEmployees() {
    return mode_.listAllEmployees();
}
