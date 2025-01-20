#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

class ServiceMode {
public:
    virtual void displayMenu() = 0;  // ��ʾ�˵�
    virtual void handleInput() = 0;  // �����û�����
    virtual ~ServiceMode() = default;
};

#endif // SERVICE_MODE_H
