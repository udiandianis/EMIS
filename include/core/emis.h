#ifndef EMIS_H
#define EMIS_H

#include <string>

extern const std::string ID_FILE;        // ΨһID�������ļ�
extern const std::string MANAGER_FILE;   // ����Ա��Ϣ���ݿ�
extern const std::string SERVICE_FILE;   // ���ż�Ա����Ϣ���ݿ�

// ��ʼ��ϵͳ
void initializeSystem();

// ����ϵͳ����
void saveData();

// ����ϵͳ����
void loadData();

#endif // EMIS_H
