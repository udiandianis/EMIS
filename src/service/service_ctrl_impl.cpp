#include "service_ctrl_impl.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void ServiceCtrlImpl::addDepartment(const std::string& name) {
    int newId = departments.empty() ? 101 : departments.back().getId() + 1;
    departments.emplace_back(newId, name);
    std::cout << "���� " << name << " �ѳɹ���ӣ�IDΪ " << newId << "\n";
}

void ServiceCtrlImpl::deleteDepartment(int id) {
    auto it = std::remove_if(departments.begin(), departments.end(),
        [id](const Department& dept) { return dept.getId() == id; });
    if (it != departments.end()) {
        departments.erase(it, departments.end());
        std::cout << "���� ID " << id << " ��ɾ����\n";
    }
    else {
        std::cout << "δ�ҵ����� ID " << id << "��\n";
    }
}

std::vector<Department> ServiceCtrlImpl::listDepartments() const {
    return departments;
}

void ServiceCtrlImpl::addEmployee(const std::string& name, char gender, int age, int departmentId) {
    int newId = employees.empty() ? 1001 : employees.back().getId() + 1;
    employees.emplace_back(newId, name, gender, age, departmentId);
    std::cout << "Ա�� " << name << " �ѳɹ���ӣ�IDΪ " << newId << "������IDΪ " << departmentId << "\n";
}

void ServiceCtrlImpl::deleteEmployee(int id) {
    auto it = std::remove_if(employees.begin(), employees.end(),
        [id](const Employee& emp) { return emp.getId() == id; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        std::cout << "Ա�� ID " << id << " ��ɾ����\n";
    }
    else {
        std::cout << "δ�ҵ�Ա�� ID " << id << "��\n";
    }
}

std::vector<Employee> ServiceCtrlImpl::listEmployees(int departmentId) const {
    std::vector<Employee> result;
    for (const auto& emp : employees) {
        if (emp.getDepartmentId() == departmentId) {
            result.push_back(emp);
        }
    }
    return result;
}

void ServiceCtrlImpl::saveServiceDataToFile(const char* filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "����: �޷�д���ļ� " << filename << "��\n";
        return;
    }

    // ���沿������
    for (const auto& dept : departments) {
        file << dept.getId() << " " << dept.getName() << "\n";
    }

    // ����Ա������
    for (const auto& emp : employees) {
        file << emp.getId() << " " << emp.getName() << " " << emp.getGender()
            << " " << emp.getAge() << " " << emp.getDepartmentId() << "\n";
    }

    file.close();
    std::cout << "���ź�Ա�������ѱ��浽�ļ� " << filename << "��\n";
}

void ServiceCtrlImpl::loadServiceDataFromFile(const char* filename) {
    departments.clear();
    employees.clear();

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "����: �޷����ļ� " << filename << "��\n";
        return;
    }

    int id, age, departmentId;
    char gender;
    std::string name;

    while (file >> id) {
        file >> name;
        if (file.peek() == '\n') { // �����һ���ǻ��з�����Ϊ��������
            departments.emplace_back(id, name);
        }
        else { // ����ΪԱ������
            file >> gender >> age >> departmentId;
            employees.emplace_back(id, name, gender, age, departmentId);
        }
    }

    file.close();
    std::cout << "���ź�Ա�������Ѵ��ļ� " << filename << " ���ء�\n";
}
