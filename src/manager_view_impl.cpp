#include "manager_view_impl.h"
#include <iostream>

void ManagerViewImpl::displayManagerList(const std::vector<Manager>& managers) {
    for (const auto& manager : managers) {
        std::cout << "ID: " << manager.id << ", �û���: " << manager.username << std::endl;
    }
}

void ManagerViewImpl::displayManagerDetails(const Manager& manager) {
    std::cout << "����ԱID: " << manager.id << ", �û���: " << manager.username << ", ����: " << manager.password << std::endl;
}

std::pair<std::string, std::string> ManagerViewImpl::promptForManagerInput() {
    std::pair<std::string, std::string> result;
    std::cout << "���������Ա���û���: ";
    std::cin >> result.first;   // �û���
    std::cout << "���������Ա������: ";
    std::cin >> result.second;  // ����
    return result;
}
