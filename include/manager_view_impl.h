#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include <utility>    // std::pair
#include <string>

/**
 * ManagerViewImpl �� ManagerView �ľ���ʵ���ࡣ
 * ���� promptForManagerInput() ���Ⱥ���ʾ����ȡ�û��������룬
 * ������һ�� {username, password} �Ķ�Ԫ�顣
 */
class ManagerViewImpl : public ManagerView {
public:
    // ��ʾ���й���Ա�б�
    void displayManagerList(const std::vector<Manager>& managers) override;

    // ��ʾ��������Ա����
    void displayManagerDetails(const Manager& manager) override;

    // �޸ģ�����һ�� pair<string, string>���ֱ��� (username, password)
    std::pair<std::string, std::string> promptForManagerInput() override;
};

#endif // MANAGER_VIEW_IMPL_H
