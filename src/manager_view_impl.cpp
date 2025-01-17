#include "manager_view_impl.h"
#include <iostream>

// ��ʾ���й���Ա������ʾ����
void ManagerViewImpl::displayManagerList(const std::vector<Manager>& managers) {
    for (const auto& mgr : managers) {
        std::cout << "ID: " << mgr.getId()
            << ", �û���: " << mgr.getUsername()
            << ", ����: " << mgr.getPassword() << "\n";
    }
}

// ��ʾ��������Ա����
void ManagerViewImpl::displayManagerDetails(const Manager& manager) {
    std::cout << "����ԱID: " << manager.getId()
        << ", �û���: " << manager.getUsername()
        << ", ����: " << manager.getPassword() << "\n";
}

// ��ȡ�û��������벢����
std::pair<std::string, std::string> ManagerViewImpl::promptForManagerInput() {
    std::string username, password;
    std::cout << "���������Ա���û���: ";
    std::cin >> username;
    std::cout << "���������Ա������: ";
    std::cin >> password;
    return { username, password };
}
