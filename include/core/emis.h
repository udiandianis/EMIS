#ifndef EMIS_H
#define EMIS_H

extern const char* ID_FILE;        // ΨһID�������ļ�
extern const char* MANAGER_FILE;   // ����Ա��Ϣ���ݿ�
extern const char* SERVICE_FILE;   // ���ż�Ա����Ϣ���ݿ�

// ��ʼ��ϵͳ
void initializeSystem();

// ����ϵͳ����
void saveData();

// ����ϵͳ����
void loadData();

#endif // EMIS_H
