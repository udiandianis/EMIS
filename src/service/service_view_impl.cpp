#include <iostream>
#include <string>

#include "service_ctrl.h"
#include "service_view_impl.h"

void ServiceViewImpl::setServiceCtrl(ServiceCtrl* ctrl) {
    ctrl_ = ctrl;
}

void ServiceViewImpl::menu() {
    if (!ctrl_) {
        std::cout << "[Error] 未绑定 ServiceCtrl.\n";
        return;
    }

    bool running = true;
    while (running) {
        std::cout << "\n=== 业务子系统菜单 ===\n"
            << "1. 增加部门\n"
            << "2. 删除部门\n"
            << "3. 列出所有部门\n"
            << "4. 增加员工\n"
            << "5. 删除员工\n"
            << "6. 修改员工信息\n"
            << "7. 列出某部门员工\n"
            << "8. 列出所有员工\n"
            << "0. 返回上级菜单\n"
            << "======================\n"
            << "请选择: ";

        int choice = 0;
        std::cin >> choice;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            std::string deptName;
            std::cout << "输入部门名称: ";
            std::cin >> deptName;
            ctrl_->addDepartment(deptName);
            break;
        }
        case 2: {
            int deptId = 0;
            std::cout << "输入要删除的部门ID: ";
            std::cin >> deptId;
            ctrl_->delDepartment(deptId);
            break;
        }
        case 3:
            ctrl_->listDepartment();
            break;
        case 4: {
            std::string name;
            char c;
            int age, deptId;
            std::cout << "输入员工姓名: ";
            std::cin >> name;
            std::cout << "输入性别(m=男,w=女): ";
            std::cin >> c;
            bool isMale = (c == 'm');
            std::cout << "输入年龄: ";
            std::cin >> age;
            std::cout << "输入所属部门ID: ";
            std::cin >> deptId;

            ctrl_->addEmployee(name, isMale, age, deptId);
            break;
        }
        case 5: {
            int empId = 0;
            std::cout << "输入要删除的员工ID: ";
            std::cin >> empId;
            ctrl_->delEmployee(empId);
            break;
        }
        case 6: {
            int empId = 0;
            std::cout << "输入要修改的员工ID: ";
            std::cin >> empId;
            ctrl_->modifyEmployee(empId);
            break;
        }
        case 7: {
            int deptId = 0;
            std::cout << "输入部门ID: ";
            std::cin >> deptId;
            ctrl_->listDeptEmployees(deptId);
            break;
        }
        case 8:
            ctrl_->listAllEmployees();
            break;
        case 0:
            running = false;
            break;
        default:
            std::cout << "无效选项.\n";
            break;
        }
    }
}
