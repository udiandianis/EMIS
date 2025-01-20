#include "core/emis.h"
#include "manager/manager_ctrl_impl.h"
#include "manager/manager_mode_impl.h"
#include "service/service_ctrl_impl.h"
#include "service/service_mode_impl.h"
#include <iostream>

// ȫ�ֱ�������
ManagerCtrlImpl managerCtrl; // ����Ա������
ServiceCtrlImpl serviceCtrl; // ���������

// ���˵���ʾ
void displayMainMenu() {
    std::cout << "\n=== ��ҵ����ϵͳ ===\n";
    std::cout << "1. ����Ա����\n";
    std::cout << "2. ������Ա������\n";
    std::cout << "3. �˳�ϵͳ\n";
    std::cout << "������������: ";
}

// ���������
int main() {
    initializeSystem(); // ��ʼ��ϵͳ����������

    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            ManagerModeImpl managerMode(&managerCtrl);
            managerMode.displayMenu();
            managerMode.handleInput();
            break;
        }
        case 2: {
            ServiceModeImpl serviceMode(&serviceCtrl);
            serviceMode.displayMenu();
            serviceMode.handleInput();
            break;
        }
        case 3:
            std::cout << "\n���ڱ���ϵͳ����...\n";
            saveData(); // ������������
            std::cout << "ϵͳ���ݱ���ɹ������򼴽��˳�...\n";
            return 0;
        default:
            std::cout << "��Ч���������������롣\n";
        }
    }

    return 0;
}
