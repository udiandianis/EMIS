#include <iostream>
#include <string>

#include "service_ctrl.h"
#include "service_view_impl.h"

void ServiceViewImpl::setServiceCtrl(ServiceCtrl* ctrl) {
    ctrl_ = ctrl;
}

void ServiceViewImpl::menu() {
    if (!ctrl_) {
        std::cout << "[Error] δ�� ServiceCtrl.\n";
        return;
    }

    bool running = true;
    while (running) {
        std::cout << "\n=== ҵ����ϵͳ�˵� ===\n"
            << "1. ���Ӳ���\n"
            << "2. ɾ������\n"
            << "3. �г����в���\n"
            << "4. ����Ա��\n"
            << "5. ɾ��Ա��\n"
            << "6. �޸�Ա����Ϣ\n"
            << "7. �г�ĳ����Ա��\n"
            << "8. �г�����Ա��\n"
            << "0. �����ϼ��˵�\n"
            << "======================\n"
            << "��ѡ��: ";

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
            std::cout << "���벿������: ";
            std::cin >> deptName;
            ctrl_->addDepartment(deptName);
            break;
        }
        case 2: {
            int deptId = 0;
            std::cout << "����Ҫɾ���Ĳ���ID: ";
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
            std::cout << "����Ա������: ";
            std::cin >> name;
            std::cout << "�����Ա�(m=��,w=Ů): ";
            std::cin >> c;
            bool isMale = (c == 'm');
            std::cout << "��������: ";
            std::cin >> age;
            std::cout << "������������ID: ";
            std::cin >> deptId;

            ctrl_->addEmployee(name, isMale, age, deptId);
            break;
        }
        case 5: {
            int empId = 0;
            std::cout << "����Ҫɾ����Ա��ID: ";
            std::cin >> empId;
            ctrl_->delEmployee(empId);
            break;
        }
        case 6: {
            int empId = 0;
            std::cout << "����Ҫ�޸ĵ�Ա��ID: ";
            std::cin >> empId;
            ctrl_->modifyEmployee(empId);
            break;
        }
        case 7: {
            int deptId = 0;
            std::cout << "���벿��ID: ";
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
            std::cout << "��Чѡ��.\n";
            break;
        }
    }
}
