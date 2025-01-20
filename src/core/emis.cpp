#include "emis.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "manager/manager_ctrl_impl.h"
#include "service/service_ctrl_impl.h"


// ��̬������Ŀ��Ŀ¼
std::string getProjectRoot() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    while (!currentPath.empty()) {
        if (std::filesystem::exists(currentPath / "data")) { // ���� data ����Ŀ��Ŀ¼�ı�־
            return currentPath.string();
        }
        currentPath = currentPath.parent_path(); // ����һ��Ŀ¼����
    }

    throw std::runtime_error("δ�ҵ���Ŀ��Ŀ¼��ȷ������ 'data' �ļ���");
}

// �ļ�·������
const std::string ID_FILE = getProjectRoot() + "\\data\\id.dat";
const std::string MANAGER_FILE = getProjectRoot() + "\\data\\managers.dat";
const std::string SERVICE_FILE = getProjectRoot() + "\\data\\services.dat";


// ȫ�ֿ���������
extern ManagerCtrlImpl managerCtrl;   // ����Ա������
extern ServiceCtrlImpl serviceCtrl;  // ���������

void debugFilePaths() {
    std::cout << "��ǰ����Ŀ¼: " << std::filesystem::current_path() << std::endl;
    std::cout << "ID �ļ�·��: " << ID_FILE << std::endl;
    std::cout << "����Ա�ļ�·��: " << MANAGER_FILE << std::endl;
    std::cout << "�����ļ�·��: " << SERVICE_FILE << std::endl;
}

void initializeSystem() {
    std::cout << "���ڳ�ʼ��ϵͳ...\n";

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
    managerCtrl.saveManagersToFile(MANAGER_FILE);
    serviceCtrl.saveServiceDataToFile(SERVICE_FILE);
}

void loadData() {
    managerCtrl.loadManagersFromFile(MANAGER_FILE);
    serviceCtrl.loadServiceDataFromFile(SERVICE_FILE);
}
