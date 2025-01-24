#include <fstream>
#include <iostream>

#include "emis.h"  // ʹ�� EMIS::g_managerDataFile
#include "manager.h"
#include "manager_mode_impl.h"
#include "tools.h"

int ManagerModeImpl::init() {
    managers_.clear();
    std::ifstream ifs(EMIS::g_managerDataFile, std::ios::binary);
    if (!ifs.is_open()) {
        // �ļ�������
        return 0;
    }

    while (true) {
        int id = 0;
        if (!ifs.read(reinterpret_cast<char*>(&id), sizeof(id))) {
            break;
        }

        int nameLen = 0;
        if (!ifs.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen))) {
            break;
        }
        std::string name;
        name.resize(nameLen);
        if (nameLen > 0) {
            ifs.read(&name[0], nameLen);
        }

        int pwdLen = 0;
        if (!ifs.read(reinterpret_cast<char*>(&pwdLen), sizeof(pwdLen))) {
            break;
        }
        std::string pwd;
        pwd.resize(pwdLen);
        if (pwdLen > 0) {
            ifs.read(&pwd[0], pwdLen);
        }

        managers_.emplace_back(id, name, pwd);
    }
    ifs.close();
    return 0;
}

int ManagerModeImpl::save() {
    std::ofstream ofs(EMIS::g_managerDataFile, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open()) {
        std::cout << "[Error] �� " << EMIS::g_managerDataFile << " ʧ��\n";
        return -1;
    }

    for (auto& m : managers_) {
        int id = m.getId();
        ofs.write(reinterpret_cast<const char*>(&id), sizeof(id));

        int nameLen = static_cast<int>(m.getName().size());
        ofs.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        if (nameLen > 0) {
            ofs.write(m.getName().data(), nameLen);
        }

        int pwdLen = static_cast<int>(m.getPassword().size());
        ofs.write(reinterpret_cast<const char*>(&pwdLen), sizeof(pwdLen));
        if (pwdLen > 0) {
            ofs.write(m.getPassword().data(), pwdLen);
        }
    }
    ofs.close();
    return 0;
}

int ManagerModeImpl::addManager(const std::string& name, const std::string& password) {
    int newId = getNewManagerId();
    if (newId < 0) {
        std::cout << "[Error] �޷������µĹ���ԱID.\n";
        return -1;
    }

    managers_.emplace_back(newId, name, password);
    std::cout << "[OK] ����ӹ���Ա: ID=" << newId << ", �û���=" << name << std::endl;
    return 0;
}

int ManagerModeImpl::delManager(int managerId) {
    for (auto it = managers_.begin(); it != managers_.end(); ++it) {
        if (it->getId() == managerId) {
            managers_.erase(it);
            std::cout << "[OK] ��ɾ������ԱID=" << managerId << std::endl;
            return 0;
        }
    }
    std::cout << "[Error] δ�ҵ�ID=" << managerId << "�Ĺ���Ա.\n";
    return -1;
}

int ManagerModeImpl::listManager() {
    if (managers_.empty()) {
        std::cout << "[Info] ��ǰû�й���Ա.\n";
        return 0;
    }
    std::cout << "\n======== ����Ա�б� ========\n";
    for (auto& m : managers_) {
        std::cout << "ID��" << m.getId() << "  �û�����" << m.getName() << "  ���룺" << m.getPassword() << "\n";
    }
    return 0;
}
