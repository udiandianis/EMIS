#include "manager_ctrl_impl.h"
#include <iostream>

void ManagerCtrlImpl::addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password) {
    int newId = managers.empty() ? 1001 : managers.back().id + 1;
    Manager newManager(newId, username, password);
    managers.push_back(newManager);
    std::cout << "����Ա " << username << " �ѳɹ���ӣ�IDΪ " << newId << std::endl << std::endl;
}

void ManagerCtrlImpl::deleteManager(std::vector<Manager>& managers, int managerId) {
    auto it = std::remove_if(managers.begin(), managers.end(), [managerId](const Manager& m) {
        return m.id == managerId;
        });

    if (it != managers.end()) {
        managers.erase(it, managers.end());
        std::cout << "����Ա ID " << managerId << " ��ɾ����" << std::endl;
    }
    else {
        std::cout << "δ�ҵ� ID " << managerId << " �Ĺ���Ա��" << std::endl;
    }
}

void ManagerCtrlImpl::listAllManagers(const std::vector<Manager>& managers) {
    std::cout << "����Ա�б�" << std::endl;
    for (const auto& manager : managers) {
        std::cout << "ID: " << manager.id << ", �û���: " << manager.username << std::endl;
    }
    std::cout << std::endl;
}
