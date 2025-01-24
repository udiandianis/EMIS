#pragma once

#include <string>

class ManagerCtrl {
public:
    virtual ~ManagerCtrl() = default;

    // ��ӹ���Ա
    virtual int addManager(const std::string& name, const std::string& password) = 0;
    // ɾ������Ա
    virtual int delManager(int managerId) = 0;
    // �г����й���Ա
    virtual int listManager() = 0;
};
