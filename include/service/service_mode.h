#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

class ServiceMode {
public:
    virtual void displayMenu() = 0;  // 显示菜单
    virtual void handleInput() = 0;  // 处理用户输入
    virtual ~ServiceMode() = default;
};

#endif // SERVICE_MODE_H
