#include "service_view_impl.h"
#include <iostream>

ServiceViewImpl::ServiceViewImpl(ServiceCtrl* ctrl) : controller(ctrl) {}

void ServiceViewImpl::showDepartmentList() {
    auto departments = controller->listDepartments();
    if (departments.empty()) {
        std::cout << "��ǰû���κβ��š�\n";
    }
    else {
        std::cout << "\n=== �����б���Ա�������� ===\n";
        for (const auto& dept : departments) {
            int employeeCount = controller->listEmployees(dept.getId()).size();
            std::cout << "ID: " << dept.getId()
                << ", ����: " << dept.getName()
                << ", Ա������: " << employeeCount << "\n";
        }
    }
}

void ServiceViewImpl::showEmployeeList(int departmentId) {
    auto employees = controller->listEmployees(departmentId);
    if (employees.empty()) {
        std::cout << "�ò���û��Ա����\n";
    }
    else {
        std::cout << "\n=== ���� " << departmentId << " ��Ա���б� ===\n";
        for (const auto& emp : employees) {
            std::cout << "ID: " << emp.getId()
                << ", ����: " << emp.getName()
                << ", �Ա�: " << emp.getGender()
                << ", ����: " << emp.getAge() << "\n";
        }
    }
}

void ServiceViewImpl::showAddDepartmentResult(bool success, const std::string& departmentName) {
    if (success) {
        std::cout << "���� \"" << departmentName << "\" �ѳɹ���ӡ�\n";
    }
    else {
        std::cout << "��Ӳ���ʧ�ܡ�\n";
    }
}

void ServiceViewImpl::showDeleteDepartmentResult(bool success, int departmentId) {
    if (success) {
        std::cout << "���� ID " << departmentId << " �ѳɹ�ɾ����\n";
    }
    else {
        std::cout << "ɾ������ʧ�ܣ�δ�ҵ� ID Ϊ " << departmentId << " �Ĳ��š�\n";
    }
}

void ServiceViewImpl::showAddEmployeeResult(bool success, const std::string& employeeName) {
    if (success) {
        std::cout << "Ա�� \"" << employeeName << "\" �ѳɹ���ӡ�\n";
    }
    else {
        std::cout << "���Ա��ʧ�ܡ�\n";
    }
}

void ServiceViewImpl::showDeleteEmployeeResult(bool success, int employeeId) {
    if (success) {
        std::cout << "Ա�� ID " << employeeId << " �ѳɹ�ɾ����\n";
    }
    else {
        std::cout << "ɾ��Ա��ʧ�ܣ�δ�ҵ� ID Ϊ " << employeeId << " ��Ա����\n";
    }
}
