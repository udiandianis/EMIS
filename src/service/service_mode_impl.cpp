#include "service_mode_impl.h"
#include "service_view_impl.h"
#include <iostream>

ServiceModeImpl::ServiceModeImpl(ServiceCtrl* ctrl, ServiceView* view)
    : controller(ctrl), viewer(view) {}

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
        viewer->showAddDepartmentResult(true, deptName); // 使用 viewer 显示结果
        break;
    }
    case 2: {
        int deptId;
        std::cout << "请输入要删除的部门 ID: ";
        std::cin >> deptId;
        controller->deleteDepartment(deptId);
        viewer->showDeleteDepartmentResult(true, deptId); // 使用 viewer 显示结果
        break;
    }
    case 3: {
        viewer->showDepartmentList();
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
        viewer->showAddEmployeeResult(true, empName); // 使用 viewer 显示结果
        break;
    }
    case 5: {
        int empId;
        std::cout << "请输入要删除的员工 ID: ";
        std::cin >> empId;
        controller->deleteEmployee(empId);
        viewer->showDeleteEmployeeResult(true, empId); // 使用 viewer 显示结果
        break;
    }
    case 6: {
        int deptId;
        std::cout << "请输入部门 ID: ";
        std::cin >> deptId;
        viewer->showEmployeeList(deptId);
        break;
    }
    case 7:
        std::cout << "正在返回主菜单。\n";
        break;
    default:
        std::cout << "无效操作。\n";
    }
}
