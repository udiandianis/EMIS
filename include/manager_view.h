#pragma once

class ManagerCtrl;

class ManagerView {
public:
    virtual ~ManagerView() = default;

    // 显示管理员菜单
    virtual void menu() = 0;
    // 绑定业务逻辑控制器
    virtual void setManagerCtrl(ManagerCtrl* ctrl) = 0;
};
