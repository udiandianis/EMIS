#include "emis.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "manager/manager_ctrl_impl.h"
#include "service/service_ctrl_impl.h"


// 动态解析项目根目录
std::string getProjectRoot() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    while (!currentPath.empty()) {
        if (std::filesystem::exists(currentPath / "data")) { // 假设 data 是项目根目录的标志
            return currentPath.string();
        }
        currentPath = currentPath.parent_path(); // 向上一级目录查找
    }

    throw std::runtime_error("未找到项目根目录，确保存在 'data' 文件夹");
}

// 文件路径声明
const std::string ID_FILE = getProjectRoot() + "\\data\\id.dat";
const std::string MANAGER_FILE = getProjectRoot() + "\\data\\managers.dat";
const std::string SERVICE_FILE = getProjectRoot() + "\\data\\services.dat";


// 全局控制器声明
extern ManagerCtrlImpl managerCtrl;   // 管理员控制器
extern ServiceCtrlImpl serviceCtrl;  // 服务控制器

void debugFilePaths() {
    std::cout << "当前工作目录: " << std::filesystem::current_path() << std::endl;
    std::cout << "ID 文件路径: " << ID_FILE << std::endl;
    std::cout << "管理员文件路径: " << MANAGER_FILE << std::endl;
    std::cout << "服务文件路径: " << SERVICE_FILE << std::endl;
}

void initializeSystem() {
    std::cout << "正在初始化系统...\n";

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
    managerCtrl.saveManagersToFile(MANAGER_FILE);
    serviceCtrl.saveServiceDataToFile(SERVICE_FILE);
}

void loadData() {
    managerCtrl.loadManagersFromFile(MANAGER_FILE);
    serviceCtrl.loadServiceDataFromFile(SERVICE_FILE);
}
