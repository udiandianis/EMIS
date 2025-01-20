#ifndef EMIS_H
#define EMIS_H

extern const char* ID_FILE;        // 唯一ID号配置文件
extern const char* MANAGER_FILE;   // 管理员信息数据库
extern const char* SERVICE_FILE;   // 部门及员工信息数据库

// 初始化系统
void initializeSystem();

// 保存系统数据
void saveData();

// 加载系统数据
void loadData();

#endif // EMIS_H
