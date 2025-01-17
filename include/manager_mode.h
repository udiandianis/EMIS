#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include <vector>
#include "Manager.h"
#include "manager_ctrl.h"
#include "manager_view.h"

class ManagerMode {
public:
    virtual ~ManagerMode() = default;

    // ���й���ģʽ����ʾ�˵��������û�ѡ��
    virtual void run(ManagerCtrl& ctrl, ManagerView& view, std::vector<Manager>& managers) = 0;
};

#endif // MANAGER_MODE_H
