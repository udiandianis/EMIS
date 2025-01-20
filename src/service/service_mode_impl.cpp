#include "service_mode_impl.h"
#include <iostream>

ServiceModeImpl::ServiceModeImpl(ServiceCtrl* ctrl) : controller(ctrl) {}

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
        break;
    }
    case 2: {
        int deptId;
        std::cout << "������Ҫɾ���Ĳ��� ID: ";
        std::cin >> deptId;
        controller->deleteDepartment(deptId);
        break;
    }
    case 3: {
        auto departments = controller->listDepartments();
        if (departments.empty()) {
            std::cout << "��ǰû���κβ��š�\n";
        }
        else {
            std::cout << "�����б�:\n";
            for (const auto& dept : departments) {
                std::cout << "ID: " << dept.getId() << ", ����: " << dept.getName() << "\n";
            }
        }
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
        break;
    }
    case 5: {
        int empId;
        std::cout << "������Ҫɾ����Ա�� ID: ";
        std::cin >> empId;
        controller->deleteEmployee(empId);
        break;
    }
    case 6: {
        int deptId;
        std::cout << "�����벿�� ID: ";
        std::cin >> deptId;
        auto employees = controller->listEmployees(deptId);
        if (employees.empty()) {
            std::cout << "�ò���û��Ա����\n";
        }
        else {
            std::cout << "Ա���б�:\n";
            for (const auto& emp : employees) {
                std::cout << "ID: " << emp.getId()
                    << ", ����: " << emp.getName()
                    << ", �Ա�: " << emp.getGender()
                    << ", ����: " << emp.getAge() << "\n";
            }
        }
        break;
    }
    case 7:
        std::cout << "�������˵���\n";
        break;
    default:
        std::cout << "��Ч������\n";
    }
}
