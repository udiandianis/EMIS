#pragma once

class ServiceCtrl;

class ServiceView {
public:
    virtual ~ServiceView() = default;

    // 显示业务子系统菜单
    virtual void menu() = 0;
    // 绑定业务逻辑控制器
    virtual void setServiceCtrl(ServiceCtrl* ctrl) = 0;
};
