#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

class ManagerView {
public:
    virtual void showManagerList() = 0;  // ��ʾ����Ա�б�
    virtual ~ManagerView() = default;
};

#endif // MANAGER_VIEW_H
