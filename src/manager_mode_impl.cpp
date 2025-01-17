#include "manager_mode_impl.h"
#include <iostream>

void ManagerModeImpl::run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers) {
    int choice;
    while (true) {
        std::cout << "1. ��ӹ���Ա\n2. ɾ������Ա\n3. �г����й���Ա\n4. �˳�\n������ѡ�";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {
            auto [username, password] = view.promptForManagerInput();
            ctrl.addManager(managers, username, password);
        }
        else if (choice == 2) {
            int managerId;
            std::cout << "������Ҫɾ���Ĺ���ԱID: ";
            std::cin >> managerId;
            ctrl.deleteManager(managers, managerId);
        }
        else if (choice == 3) {
            ctrl.listAllManagers(managers);
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "��Чѡ����������롣" << std::endl;
        }
    }
}
