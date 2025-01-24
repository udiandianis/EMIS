#pragma once

#include <string>

class ManagerMode {
public:
    virtual ~ManagerMode() = default;

    // ��ʼ��
    virtual int init() = 0;
    // ��������
    virtual int save() = 0;

    // ҵ�����
    virtual int addManager(const std::string& name, const std::string& password) = 0;
    virtual int delManager(int managerId) = 0;
    virtual int listManager() = 0;
};
