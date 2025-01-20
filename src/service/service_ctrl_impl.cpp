#include "service_ctrl_impl.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void ServiceCtrlImpl::addDepartment(const std::string& name) {
    int newId = departments.empty() ? 101 : departments.back().getId() + 1;
    departments.emplace_back(newId, name);
    std::cout << "部门 " << name << " 已成功添加，ID为 " << newId << "\n";
}

void ServiceCtrlImpl::deleteDepartment(int id) {
    auto it = std::remove_if(departments.begin(), departments.end(),
        [id](const Department& dept) { return dept.getId() == id; });
    if (it != departments.end()) {
        departments.erase(it, departments.end());
        std::cout << "部门 ID " << id << " 已删除。\n";
    }
    else {
        std::cout << "未找到部门 ID " << id << "。\n";
    }
}

std::vector<Department> ServiceCtrlImpl::listDepartments() const {
    return departments;
}

void ServiceCtrlImpl::addEmployee(const std::string& name, char gender, int age, int departmentId) {
    int newId = employees.empty() ? 1001 : employees.back().getId() + 1;
    employees.emplace_back(newId, name, gender, age, departmentId);
    std::cout << "员工 " << name << " 已成功添加，ID为 " << newId << "，部门ID为 " << departmentId << "\n";
}

void ServiceCtrlImpl::deleteEmployee(int id) {
    auto it = std::remove_if(employees.begin(), employees.end(),
        [id](const Employee& emp) { return emp.getId() == id; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        std::cout << "员工 ID " << id << " 已删除。\n";
    }
    else {
        std::cout << "未找到员工 ID " << id << "。\n";
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
        std::cerr << "错误: 无法写入文件 " << filename << "。\n";
        return;
    }

    // 保存部门数据
    for (const auto& dept : departments) {
        file << dept.getId() << " " << dept.getName() << "\n";
    }

    // 保存员工数据
    for (const auto& emp : employees) {
        file << emp.getId() << " " << emp.getName() << " " << emp.getGender()
            << " " << emp.getAge() << " " << emp.getDepartmentId() << "\n";
    }

    file.close();
    std::cout << "部门和员工数据已保存到文件 " << filename << "。\n";
}

void ServiceCtrlImpl::loadServiceDataFromFile(const char* filename) {
    departments.clear();
    employees.clear();

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "警告: 无法打开文件 " << filename << "。\n";
        return;
    }

    int id, age, departmentId;
    char gender;
    std::string name;

    while (file >> id) {
        file >> name;
        if (file.peek() == '\n') { // 如果下一项是换行符，则为部门数据
            departments.emplace_back(id, name);
        }
        else { // 否则为员工数据
            file >> gender >> age >> departmentId;
            employees.emplace_back(id, name, gender, age, departmentId);
        }
    }

    file.close();
    std::cout << "部门和员工数据已从文件 " << filename << " 加载。\n";
}
