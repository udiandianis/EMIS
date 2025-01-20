#include "service_view_impl.h"
#include <iostream>

ServiceViewImpl::ServiceViewImpl(ServiceCtrl* ctrl) : controller(ctrl) {}

void ServiceViewImpl::showDepartmentList() {
    auto departments = controller->listDepartments();
    if (departments.empty()) {
        std::cout << "当前没有任何部门。\n";
    }
    else {
        std::cout << "\n=== 部门列表（含员工人数） ===\n";
        for (const auto& dept : departments) {
            int employeeCount = controller->listEmployees(dept.getId()).size();
            std::cout << "ID: " << dept.getId()
                << ", 名称: " << dept.getName()
                << ", 员工人数: " << employeeCount << "\n";
        }
    }
}

void ServiceViewImpl::showEmployeeList(int departmentId) {
    auto employees = controller->listEmployees(departmentId);
    if (employees.empty()) {
        std::cout << "该部门没有员工。\n";
    }
    else {
        std::cout << "\n=== 部门 " << departmentId << " 的员工列表 ===\n";
        for (const auto& emp : employees) {
            std::cout << "ID: " << emp.getId()
                << ", 姓名: " << emp.getName()
                << ", 性别: " << emp.getGender()
                << ", 年龄: " << emp.getAge() << "\n";
        }
    }
}

void ServiceViewImpl::showAddDepartmentResult(bool success, const std::string& departmentName) {
    if (success) {
        std::cout << "部门 \"" << departmentName << "\" 已成功添加。\n";
    }
    else {
        std::cout << "添加部门失败。\n";
    }
}

void ServiceViewImpl::showDeleteDepartmentResult(bool success, int departmentId) {
    if (success) {
        std::cout << "部门 ID " << departmentId << " 已成功删除。\n";
    }
    else {
        std::cout << "删除部门失败，未找到 ID 为 " << departmentId << " 的部门。\n";
    }
}

void ServiceViewImpl::showAddEmployeeResult(bool success, const std::string& employeeName) {
    if (success) {
        std::cout << "员工 \"" << employeeName << "\" 已成功添加。\n";
    }
    else {
        std::cout << "添加员工失败。\n";
    }
}

void ServiceViewImpl::showDeleteEmployeeResult(bool success, int employeeId) {
    if (success) {
        std::cout << "员工 ID " << employeeId << " 已成功删除。\n";
    }
    else {
        std::cout << "删除员工失败，未找到 ID 为 " << employeeId << " 的员工。\n";
    }
}
