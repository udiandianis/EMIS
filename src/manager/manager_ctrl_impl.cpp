#include "manager_ctrl_impl.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "tools.h"
#include "emis.h"

void ManagerCtrlImpl::addManager(const std::string& name, const std::string& password) {
    int newId = generateUniqueID(ID_FILE);
    managers.emplace_back(newId, name, password);
    std::cout << "����Ա��ӳɹ���ID: " << newId << "���û���: " << name << "\n";
}

void ManagerCtrlImpl::deleteManager(int id) {
    auto it = std::remove_if(managers.begin(), managers.end(),
        [id](const Manager& m) { return m.getId() == id; });
    if (it != managers.end()) {
        managers.erase(it, managers.end());
        std::cout << "����Աɾ���ɹ���ID: " << id << "\n";
    }
    else {
        std::cout << "δ�ҵ�����Ա ID: " << id << "\n";
    }
}

std::vector<Manager> ManagerCtrlImpl::listManagers() const {
    return managers;
}

void ManagerCtrlImpl::saveManagersToFile(const char* filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "�޷����ļ��������Ա���ݣ�\n";
        return;
    }

    for (const auto& manager : managers) {
        file << manager.getId() << " "
            << manager.getUsername() << " "
            << manager.getPassword() << "\n";
    }
    file.close();
    std::cout << "����Ա�����ѱ��档\n";
}

void ManagerCtrlImpl::loadManagersFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "�޷����ļ����ع���Ա���ݣ�\n";
        return;
    }

    managers.clear();
    int id;
    std::string username, password;

    while (file >> id >> username >> password) {
        managers.emplace_back(id, username, password);
    }
    file.close();
    std::cout << "�Ѽ��� " << managers.size() << " ������Ա��\n";
}
