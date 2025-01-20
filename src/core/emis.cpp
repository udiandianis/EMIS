#include "emis.h"
#include <fstream>
#include <iostream>
#include "manager/manager_ctrl_impl.h"
#include "service/service_ctrl_impl.h"

// 文件路径声明
const char* ID_FILE = "F:\\q\\EMIS\\data\\id.dat";
const char* MANAGER_FILE = "F:\\q\\EMIS\\data\\managers.dat";
const char* SERVICE_FILE = "F:\\q\\EMIS\\data\\services.dat";

// 全局控制器声明
extern ManagerCtrlImpl managerCtrl;   // 管理员控制器
extern ServiceCtrlImpl serviceCtrl;  // 服务控制器

void initializeSystem() {
    std::cout << "初始化系统...\n";

    // 确保数据文件存在，但不清空文件内容
    std::ofstream idFile(ID_FILE, std::ios::app | std::ios::binary);        // 追加模式
    std::ofstream managerFile(MANAGER_FILE, std::ios::app | std::ios::binary); // 追加模式
    std::ofstream serviceFile(SERVICE_FILE, std::ios::app | std::ios::binary); // 追加模式
    idFile.close();
    managerFile.close();
    serviceFile.close();

    loadData(); // 加载文件中的数据到内存
}

void saveData() {
    std::cout << "保存数据到文件...\n";
    managerCtrl.saveManagersToFile(MANAGER_FILE);
    serviceCtrl.saveServiceDataToFile(SERVICE_FILE);
    std::cout << "数据保存完成！\n";
}

void loadData() {
    std::cout << "从文件加载数据...\n";
    managerCtrl.loadManagersFromFile(MANAGER_FILE);
    serviceCtrl.loadServiceDataFromFile(SERVICE_FILE);
    std::cout << "数据加载完成！\n";
}
