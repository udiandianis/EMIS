#include <iostream>
#include "core/emis.h"
#include "manager/manager_ctrl_impl.h"
#include "manager/manager_mode_impl.h"
#include "manager/manager_view_impl.h"
#include "service/service_ctrl_impl.h"
#include "service/service_mode_impl.h"
#include "service/service_view_impl.h"

// ȫ�ֿ�����ʵ��
ManagerCtrlImpl managerCtrl;
ServiceCtrlImpl serviceCtrl;

int main() {
    // ��ʼ��ϵͳ
    initializeSystem();

    // ������ͼ��ģʽ
    ManagerViewImpl managerView(&managerCtrl);
    ManagerModeImpl managerMode(&managerCtrl, &managerView);

    ServiceViewImpl serviceView(&serviceCtrl);
    ServiceModeImpl serviceMode(&serviceCtrl, &serviceView);

    int choice;
    do {
        // ���˵�
        std::cout << "\n=== ��ҵ����ϵͳ ===\n";
        std::cout << "1. ����Ա����\n";
        std::cout << "2. ��ҵ�������\n";
        std::cout << "3. �˳�ϵͳ\n";
        std::cout << "������������: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            managerMode.displayMenu();
            managerMode.handleInput();
            break;
        case 2:
            serviceMode.displayMenu();
            serviceMode.handleInput();
            break;
        case 3:
            std::cout << "\n";
            saveData();
            std::cout << "���˳�ϵͳ��\n";
            break;
        default:
            std::cout << "��Ч���������������롣\n";
        }
    } while (choice != 3);

    return 0;
}
