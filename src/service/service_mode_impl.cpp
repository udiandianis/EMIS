#include "service_mode_impl.h"
#include "service_view_impl.h"
#include <iostream>

ServiceModeImpl::ServiceModeImpl(ServiceCtrl* ctrl, ServiceView* view)
    : controller(ctrl), viewer(view) {}

void ServiceModeImpl::displayMenu() {
    std::cout << "\n=== ��ҵ�������ϵͳ ===\n";
    std::cout << "1. ��Ӳ���\n";
    std::cout << "2. ɾ������\n";
    std::cout << "3. ��ʾ���в���\n";
    std::cout << "4. ���Ա��\n";
    std::cout << "5. ɾ��Ա��\n";
    std::cout << "6. ��ʾĳ���ŵ�����Ա��\n";
    std::cout << "7. �������˵�\n";
    std::cout << "������������: ";
}

void ServiceModeImpl::handleInput() {
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // ���������

    switch (choice) {
    case 1: {
        std::string deptName;
        std::cout << "�����벿������: ";
        std::getline(std::cin, deptName);
        controller->addDepartment(deptName);
        viewer->showAddDepartmentResult(true, deptName); // ʹ�� viewer ��ʾ���
        break;
    }
    case 2: {
        int deptId;
        std::cout << "������Ҫɾ���Ĳ��� ID: ";
        std::cin >> deptId;
        controller->deleteDepartment(deptId);
        viewer->showDeleteDepartmentResult(true, deptId); // ʹ�� viewer ��ʾ���
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
        std::cout << "������Ա������: ";
        std::cin >> empName;
        std::cout << "������Ա���Ա� (m/w): ";
        std::cin >> gender;
        std::cout << "������Ա������: ";
        std::cin >> age;
        std::cout << "������Ա�����ڲ��� ID: ";
        std::cin >> deptId;
        controller->addEmployee(empName, gender, age, deptId);
        viewer->showAddEmployeeResult(true, empName); // ʹ�� viewer ��ʾ���
        break;
    }
    case 5: {
        int empId;
        std::cout << "������Ҫɾ����Ա�� ID: ";
        std::cin >> empId;
        controller->deleteEmployee(empId);
        viewer->showDeleteEmployeeResult(true, empId); // ʹ�� viewer ��ʾ���
        break;
    }
    case 6: {
        int deptId;
        std::cout << "�����벿�� ID: ";
        std::cin >> deptId;
        viewer->showEmployeeList(deptId);
        break;
    }
    case 7:
        std::cout << "���ڷ������˵���\n";
        break;
    default:
        std::cout << "��Ч������\n";
    }
}
