#pragma once

class ManagerCtrl;

class ManagerView {
public:
    virtual ~ManagerView() = default;

    // ��ʾ����Ա�˵�
    virtual void menu() = 0;
    // ��ҵ���߼�������
    virtual void setManagerCtrl(ManagerCtrl* ctrl) = 0;
};
