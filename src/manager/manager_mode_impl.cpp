#include "manager_mode_impl.h"
#include <iostream>
#include <string>

ManagerModeImpl::ManagerModeImpl(ManagerCtrl* ctrl, ManagerView* view)
    : controller(ctrl), viewer(view) {}

void ManagerModeImpl::displayMenu() {
    std::cout << "\n=== ����Ա����ϵͳ ===\n";
    std::cout << "1. ��ӹ���Ա\n";
    std::cout << "2. ɾ������Ա\n";
    std::cout << "3. ��ʾ����Ա�б�\n";
    std::cout << "4. �������˵�\n";
    std::cout << "������������: ";
}

void ManagerModeImpl::handleInput() {
    int choice;

    do {
        std::cin >> choice;
        std::cin.ignore(); // ���������
        switch (choice) {
        case 1: {
            std::string username, password;
            std::cout << "���������Ա�û���: ";
            std::getline(std::cin, username);
            std::cout << "���������Ա����: ";
            std::getline(std::cin, password);
            controller->addManager(username, password);
            break;
        }
        case 2: {
            int id;
            std::cout << "������Ҫɾ���Ĺ���Ա ID: ";
            std::cin >> id;
            controller->deleteManager(id);
            break;
        }
        case 3: {
            viewer->showManagerList();
            break;
        }
        case 4:
            std::cout << "���ڷ������˵���\n";
            return;
        default:
            std::cout << "��Ч����\n";
        }
        displayMenu();
    } while(true);
}
