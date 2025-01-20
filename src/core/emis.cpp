#include "emis.h"
#include <fstream>
#include <iostream>
#include "manager/manager_ctrl_impl.h"
#include "service/service_ctrl_impl.h"

// �ļ�·������
const char* ID_FILE = "F:\\q\\EMIS\\data\\id.dat";
const char* MANAGER_FILE = "F:\\q\\EMIS\\data\\managers.dat";
const char* SERVICE_FILE = "F:\\q\\EMIS\\data\\services.dat";

// ȫ�ֿ���������
extern ManagerCtrlImpl managerCtrl;   // ����Ա������
extern ServiceCtrlImpl serviceCtrl;  // ���������

void initializeSystem() {
    std::cout << "��ʼ��ϵͳ...\n";

    // ȷ�������ļ����ڣ���������ļ�����
    std::ofstream idFile(ID_FILE, std::ios::app | std::ios::binary);        // ׷��ģʽ
    std::ofstream managerFile(MANAGER_FILE, std::ios::app | std::ios::binary); // ׷��ģʽ
    std::ofstream serviceFile(SERVICE_FILE, std::ios::app | std::ios::binary); // ׷��ģʽ
    idFile.close();
    managerFile.close();
    serviceFile.close();

    loadData(); // �����ļ��е����ݵ��ڴ�
}

void saveData() {
    std::cout << "�������ݵ��ļ�...\n";
    managerCtrl.saveManagersToFile(MANAGER_FILE);
    serviceCtrl.saveServiceDataToFile(SERVICE_FILE);
    std::cout << "���ݱ�����ɣ�\n";
}

void loadData() {
    std::cout << "���ļ���������...\n";
    managerCtrl.loadManagersFromFile(MANAGER_FILE);
    serviceCtrl.loadServiceDataFromFile(SERVICE_FILE);
    std::cout << "���ݼ�����ɣ�\n";
}
