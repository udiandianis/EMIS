#include <iostream>
#include <vector>
#include "Manager.h"
#include "manager_ctrl_impl.h"
#include "manager_view_impl.h"
#include "manager_mode_impl.h"

int main()
{
    // �����ļ�·��
    std::string filename = "managers.dat";

    // ��������������ͼ��ģʽ����
    ManagerCtrlImpl ctrl;
    ManagerViewImpl view;
    ManagerModeImpl mode;

    // ��Ź���Ա
    std::vector<Manager> managers;

    // ����ʱ�ȼ����ļ��еĹ���Ա����
    ctrl.loadData(filename, managers);

    // ������ѭ��
    mode.run(ctrl, view, managers);

    // �˳�ǰ���浽�ļ�
    ctrl.saveData(filename, managers);

    std::cout << "�������˳����������ݵ� " << filename << "��\n";
    return 0;
}
