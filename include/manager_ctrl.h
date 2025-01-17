#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H

#include <string>
#include <vector>
#include "Manager.h"

class ManagerCtrl {
public:
    virtual ~ManagerCtrl() = default;

    // ��ӹ���Ա
    virtual void addManager(std::vector<Manager>& managers, const std::string& username, const std::string& password) = 0;

    // ɾ������Ա
    virtual void deleteManager(std::vector<Manager>& managers, int managerId) = 0;

    // �г����й���Ա
    virtual void listAllManagers(const std::vector<Manager>& managers) = 0;

    // ���ļ�����
    virtual void loadData(const std::string& filename, std::vector<Manager>& managers) = 0;

    // ���浽�ļ�
    virtual void saveData(const std::string& filename, const std::vector<Manager>& managers) = 0;
};

#endif // MANAGER_CTRL_H
