#pragma once

#include <string>

class ServiceMode {
public:
    virtual ~ServiceMode() = default;

    // ��ʼ��
    virtual int init() = 0;
    // �����ļ�
    virtual int save() = 0;

    // ���Ź���
    virtual int addDepartment(const std::string& name) = 0;
    virtual int delDepartment(int deptId) = 0;
    virtual int listDepartment() = 0;

    // Ա������
    virtual int addEmployee(const std::string& name, bool isMale, int age, int deptId) = 0;
    virtual int delEmployee(int empId) = 0;
    virtual int modifyEmployee(int empId) = 0;
    virtual int listDeptEmployees(int deptId) = 0;
    virtual int listAllEmployees() = 0;
};
