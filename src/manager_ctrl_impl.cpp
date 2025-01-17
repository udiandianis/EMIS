#include "manager_ctrl_impl.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void ManagerCtrlImpl::addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password)
{
    int newId = managers.empty() ? 1001 : managers.back().getId() + 1;
    managers.emplace_back(newId, username, password);
    std::cout << "����Ա " << username << " �ѳɹ���ӣ�IDΪ " << newId << "\n";
}

void ManagerCtrlImpl::deleteManager(std::vector<Manager>& managers, int managerId)
{
    auto it = std::remove_if(managers.begin(), managers.end(),
        [managerId](const Manager& m) {
            return m.getId() == managerId;
        });
    if (it != managers.end()) {
        managers.erase(it, managers.end());
        std::cout << "����Ա ID " << managerId << " ��ɾ����\n";
    }
    else {
        std::cout << "δ�ҵ�����Ա ID " << managerId << "��\n";
    }
}

void ManagerCtrlImpl::listAllManagers(const std::vector<Manager>& managers)
{
    if (managers.empty()) {
        std::cout << "��ǰû���κι���Ա��\n";
        return;
    }
    std::cout << "========== ����Ա�б� ==========\n";
    for (const auto& mgr : managers) {
        std::cout << "ID: " << mgr.getId()
            << ", �û���: " << mgr.getUsername()
            << ", ����: " << mgr.getPassword() << "\n";
    }
}

void ManagerCtrlImpl::loadData(const std::string& filename, std::vector<Manager>& managers)
{
    managers.clear();
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "����: �޷����ļ� " << filename << "�����ܲ����ڣ������������κι���Ա��\n";
        return;
    }

    int id;
    std::string username, password;
    while (fin >> id >> username >> password) {
        managers.emplace_back(id, username, password);
    }

    fin.close();
    std::cout << "�Ѵ��ļ� " << filename << " ���� " << managers.size() << " ������Ա��\n";
}

void ManagerCtrlImpl::saveData(const std::string& filename, const std::vector<Manager>& managers)
{
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "����: �޷�д���ļ� " << filename << "��\n";
        return;
    }

    for (const auto& mgr : managers) {
        fout << mgr.getId() << " " << mgr.getUsername() << " " << mgr.getPassword() << "\n";
    }
    fout.close();
    std::cout << "�ѽ� " << managers.size() << " ������Ա���浽�ļ� " << filename << "��\n";
}
