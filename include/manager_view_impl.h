#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include <utility> // std::pair

/**
 * ��ͼʵ����
 */
class ManagerViewImpl : public ManagerView {
public:
    // ��ʾ���й���Ա
    void displayManagerList(const std::vector<Manager>& managers) override;

    // ��ʾ��������Ա����
    void displayManagerDetails(const Manager& manager) override;

    // ��ʾ����ȡ(�û���, ����)
    // ���� {username, password}
    std::pair<std::string, std::string> promptForManagerInput() override;
};

#endif // MANAGER_VIEW_IMPL_H
