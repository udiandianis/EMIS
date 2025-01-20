#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

class ManagerView {
public:
    virtual void showManagerList() = 0;  // 显示管理员列表
    virtual ~ManagerView() = default;
};

#endif // MANAGER_VIEW_H
