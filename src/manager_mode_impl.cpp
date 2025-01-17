#include "manager_mode_impl.h"
#include <iostream>

void ManagerModeImpl::run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers)
{
    while (true) {
        std::cout << "\n===== ����Ա���� =====\n"
            << "1. ��ӹ���Ա\n"
            << "2. ɾ������Ա\n"
            << "3. �г����й���Ա\n"
            << "4. �˳�\n"
            << "������ѡ��: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // ����ͼ���ȡ�û���������
            auto [username, password] = view.promptForManagerInput();
            // ���ÿ��������
            ctrl.addManager(managers, username, password);
        }
        else if (choice == 2) {
            std::cout << "������Ҫɾ���Ĺ���ԱID: ";
            int managerId;
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
            std::cout << "��Чѡ����������롣\n";
        }
    }
}
