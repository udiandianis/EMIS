#include "service_mode_impl.h"
#include <iostream>

ServiceModeImpl::ServiceModeImpl(ServiceCtrl* ctrl) : controller(ctrl) {}

void ServiceModeImpl::displayMenu() {
    std::cout << "\n=== 企业服务管理系统 ===\n";
    std::cout << "1. 添加部门\n";
    std::cout << "2. 删除部门\n";
    std::cout << "3. 显示所有部门\n";
    std::cout << "4. 添加员工\n";
    std::cout << "5. 删除员工\n";
    std::cout << "6. 显示某部门的所有员工\n";
    std::cout << "7. 返回主菜单\n";
    std::cout << "请输入操作编号: ";
}

void ServiceModeImpl::handleInput() {
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // 清除缓冲区

    switch (choice) {
    case 1: {
        std::string deptName;
        std::cout << "请输入部门名称: ";
        std::getline(std::cin, deptName);
        controller->addDepartment(deptName);
        break;
    }
    case 2: {
        int deptId;
        std::cout << "请输入要删除的部门 ID: ";
        std::cin >> deptId;
        controller->deleteDepartment(deptId);
        break;
    }
    case 3: {
        auto departments = controller->listDepartments();
        if (departments.empty()) {
            std::cout << "当前没有任何部门。\n";
        }
        else {
            std::cout << "部门列表:\n";
            for (const auto& dept : departments) {
                std::cout << "ID: " << dept.getId() << ", 名称: " << dept.getName() << "\n";
            }
        }
        break;
    }
    case 4: {
        std::string empName;
        char gender;
        int age, deptId;
        std::cout << "请输入员工姓名: ";
        std::cin >> empName;
        std::cout << "请输入员工性别 (m/w): ";
        std::cin >> gender;
        std::cout << "请输入员工年龄: ";
        std::cin >> age;
        std::cout << "请输入员工所在部门 ID: ";
        std::cin >> deptId;
        controller->addEmployee(empName, gender, age, deptId);
        break;
    }
    case 5: {
        int empId;
        std::cout << "请输入要删除的员工 ID: ";
        std::cin >> empId;
        controller->deleteEmployee(empId);
        break;
    }
    case 6: {
        int deptId;
        std::cout << "请输入部门 ID: ";
        std::cin >> deptId;
        auto employees = controller->listEmployees(deptId);
        if (employees.empty()) {
            std::cout << "该部门没有员工。\n";
        }
        else {
            std::cout << "员工列表:\n";
            for (const auto& emp : employees) {
                std::cout << "ID: " << emp.getId()
                    << ", 姓名: " << emp.getName()
                    << ", 性别: " << emp.getGender()
                    << ", 年龄: " << emp.getAge() << "\n";
            }
        }
        break;
    }
    case 7:
        std::cout << "返回主菜单。\n";
        break;
    default:
        std::cout << "无效操作。\n";
    }
}
