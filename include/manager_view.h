#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include <vector>
#include <string>
#include "Manager.h"

/**
 * ������ͼ�ӿڣ�������ʾ����Ա�б�����Ա���飬�Լ���ʾ����ķ���
 */
class ManagerView {
public:
    virtual ~ManagerView() = default;

    // ��ʾ���й���Ա
    virtual void displayManagerList(const std::vector<Manager>& managers) = 0;

    // ��ʾ��������Ա��Ϣ
    virtual void displayManagerDetails(const Manager& manager) = 0;

    // ��ʾ����ȡ(�û���, ����)
    // ���鷵�� pair<string, string>: {username, password}
    virtual std::pair<std::string, std::string> promptForManagerInput() = 0;
};

#endif // MANAGER_VIEW_H
