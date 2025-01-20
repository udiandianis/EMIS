#include "manager_mode_impl.h"
#include <iostream>
#include <string>

ManagerModeImpl::ManagerModeImpl(ManagerCtrl* ctrl) : controller(ctrl) {}

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
    std::cin >> choice;

    switch (choice) {
    case 1: {
        std::string username, password;
        std::cout << "���������Ա�û���: ";
        std::cin >> username;
        std::cout << "���������Ա����: ";
        std::cin >> password;
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
        auto managers = controller->listManagers();
        std::cout << "\n=== ����Ա�б� ===\n";
        for (const auto& mgr : managers) {
            std::cout << "ID: " << mgr.getId() << "���û���: " << mgr.getUsername() << "\n";
        }
        break;
    }
    case 4:
        std::cout << "�������˵�\n";
        break;
    default:
        std::cout << "��Ч����\n";
    }
}
