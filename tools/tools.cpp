#include <fstream>
#include <iostream>
#include <string>

#include "emis.h"
#include "tools.h"

// 用静态变量来保存当前ID值
static int g_managerId = 100;
static int g_deptId = 100;
static int g_empId = 100;

int loadIds() {
    std::ifstream ifs(EMIS::g_idFile);
    if (!ifs.is_open()) {
        return 0;  // 文件不存在
    }
    ifs >> g_managerId >> g_deptId >> g_empId;
    if (!ifs.good()) {
        ifs.close();
        return -1;
    }
    ifs.close();
    return 0;
}

int saveIds() {
    std::ofstream ofs(EMIS::g_idFile, std::ios::trunc);
    if (!ofs.is_open()) {
        return -1;
    }
    ofs << g_managerId << " " << g_deptId << " " << g_empId << "\n";
    ofs.close();
    return 0;
}

int getNewManagerId() {
    return ++g_managerId;
}

int getNewDeptId() {
    return ++g_deptId;
}

int getNewEmpId() {
    return ++g_empId;
}
