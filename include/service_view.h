#pragma once

class ServiceCtrl;

class ServiceView {
public:
    virtual ~ServiceView() = default;

    // ��ʾҵ����ϵͳ�˵�
    virtual void menu() = 0;
    // ��ҵ���߼�������
    virtual void setServiceCtrl(ServiceCtrl* ctrl) = 0;
};
