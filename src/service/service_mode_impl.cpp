#include <fstream>
#include <iostream>

#include "emis.h"
#include "service_mode_impl.h"
#include "tools.h"

int ServiceModeImpl::init() {
    departments_.clear();
    employees_.clear();

    std::ifstream ifs(EMIS::g_serviceDataFile);
    if (!ifs.is_open()) {
        // �ļ�������
        return 0;
    }

    while (true) {
        int deptId = 0;
        ifs >> deptId;
        if (!ifs.good()) {
            break;
        }

        std::string deptName;
        ifs >> deptName;
        int empCount = 0;
        ifs >> empCount;

        departments_.emplace_back(deptId, deptName, empCount);

        // ��ȡ�ò����µ�Ա��
        for (int i = 0; i < empCount; i++) {
            int empId = 0;
            std::string empName;
            char genderChar = 0;
            int age = 0;

            ifs >> empId >> empName >> genderChar >> age;
            bool isMale = (genderChar == 'm');
            employees_.emplace_back(empId, empName, isMale, age, deptId);
        }
    }

    ifs.close();
    return 0;
}

int ServiceModeImpl::save() {
    std::ofstream ofs(EMIS::g_serviceDataFile, std::ios::trunc);
    if (!ofs.is_open()) {
        std::cout << "[Error] �� " << EMIS::g_serviceDataFile << " ʧ��.\n";
        return -1;
    }

    // ���� departments_ д��������Ϣ����ӦԱ��
    for (auto& dept : departments_) {
        ofs << dept.getId() << " " << dept.getName() << " " << dept.getEmpCount() << "\n";

        int deptId = dept.getId();
        for (auto& emp : employees_) {
            if (emp.getDeptId() == deptId) {
                char genderChar = emp.isMale() ? 'm' : 'w';
                ofs << emp.getId() << " " << emp.getName() << " " << genderChar << " " << emp.getAge() << "\n";
            }
        }
    }

    ofs.close();
    return 0;
}

// ����
int ServiceModeImpl::addDepartment(const std::string& name) {
    int newId = getNewDeptId();
    if (newId < 0) {
        std::cout << "[Error] �޷������µĲ���ID.\n";
        return -1;
    }
    departments_.emplace_back(newId, name, 0);
    std::cout << "[OK] ����Ӳ���: ID=" << newId << ", ����=" << name << std::endl;
    return 0;
}

int ServiceModeImpl::delDepartment(int deptId) {
    for (auto it = departments_.begin(); it != departments_.end(); ++it) {
        if (it->getId() == deptId) {
            // ͬʱɾ���ò���������Ա��
            for (auto empIt = employees_.begin(); empIt != employees_.end();) {
                if (empIt->getDeptId() == deptId) {
                    empIt = employees_.erase(empIt);
                }
                else {
                    ++empIt;
                }
            }

            departments_.erase(it);
            std::cout << "[OK] ��ɾ������ID=" << deptId << "����Ա��.\n";
            return 0;
        }
    }
    std::cout << "[Error] δ�ҵ�ID=" << deptId << "�Ĳ���.\n";
    return -1;
}

int ServiceModeImpl::listDepartment() {
    if (departments_.empty()) {
        std::cout << "[Info] ��ǰû���κβ���.\n";
        return 0;
    }
    std::cout << "\n=== �����б� ===\n";
    for (auto& dept : departments_) {
        std::cout << "����ID��" << dept.getId() << "  ���ƣ�" << dept.getName() << "  Ա������" << dept.getEmpCount() << "\n";
    }
    return 0;
}

// Ա��
int ServiceModeImpl::addEmployee(const std::string& name, bool isMale, int age, int deptId) {
    // ��鲿���Ƿ����
    bool found = false;
    for (auto& d : departments_) {
        if (d.getId() == deptId) {
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "[Error] ����ID=" << deptId << " ������.\n";
        return -1;
    }

    int newId = getNewEmpId();
    if (newId < 0) {
        std::cout << "[Error] ����Ա��IDʧ��.\n";
        return -1;
    }
    employees_.emplace_back(newId, name, isMale, age, deptId);

    // �������� +1
    for (auto& d : departments_) {
        if (d.getId() == deptId) {
            d.setEmpCount(d.getEmpCount() + 1);
            break;
        }
    }
    std::cout << "[OK] �����Ա��: ID��" << newId << ", ������" << name << ", ���ţ�" << deptId << std::endl;
    return 0;
}

int ServiceModeImpl::delEmployee(int empId) {
    for (auto it = employees_.begin(); it != employees_.end(); ++it) {
        if (it->getId() == empId) {
            // �������� -1
            for (auto& d : departments_) {
                if (d.getId() == it->getDeptId()) {
                    d.setEmpCount(d.getEmpCount() - 1);
                    break;
                }
            }
            employees_.erase(it);
            std::cout << "[OK] ��ɾ��Ա��ID=" << empId << std::endl;
            return 0;
        }
    }
    std::cout << "[Error] δ�ҵ�ID=" << empId << "��Ա��.\n";
    return -1;
}

int ServiceModeImpl::modifyEmployee(int empId) {
    for (auto& e : employees_) {
        if (e.getId() == empId) {
            // �޸�ѡ��
            std::cout << "��ѡ��Ҫ�޸ĵ��ֶ�:\n"
                << "1. ����\n"
                << "2. �Ա�\n"
                << "3. ����\n"
                << "4. ����ID\n"
                << "0. ȡ��\n"
                << "����ѡ��: ";
            int opt = 0;
            std::cin >> opt;

            switch (opt) {
            case 1: {
                std::string newName;
                std::cout << "������������: ";
                std::cin >> newName;
                e.setName(newName);
                std::cout << "[OK] �޸ĳɹ�.\n";
                break;
            }
            case 2: {
                char c = 0;
                std::cout << "������(m=��, w=Ů): ";
                std::cin >> c;
                e.setIsMale(c == 'm');
                std::cout << "[OK] �޸ĳɹ�.\n";
                break;
            }
            case 3: {
                int newAge = 0;
                std::cout << "������������: ";
                std::cin >> newAge;
                e.setAge(newAge);
                std::cout << "[OK] �޸ĳɹ�.\n";
                break;
            }
            case 4: {
                int oldDept = e.getDeptId();
                int newDept = 0;
                std::cout << "�������²���ID: ";
                std::cin >> newDept;

                // ����²����Ƿ����
                bool deptFound = false;
                for (auto& d : departments_) {
                    if (d.getId() == newDept) {
                        deptFound = true;
                        break;
                    }
                }
                if (!deptFound) {
                    std::cout << "[Error] ���Ų�����.\n";
                    return -1;
                }

                // ԭ�������� -1
                for (auto& d : departments_) {
                    if (d.getId() == oldDept) {
                        d.setEmpCount(d.getEmpCount() - 1);
                        break;
                    }
                }
                // �²������� +1
                for (auto& d : departments_) {
                    if (d.getId() == newDept) {
                        d.setEmpCount(d.getEmpCount() + 1);
                        break;
                    }
                }
                e.setDeptId(newDept);
                std::cout << "[OK] �޸ĳɹ�.\n";
                break;
            }
            case 0:
                std::cout << "ȡ��.\n";
                return 0;
            default:
                std::cout << "[Error] ��Ч����.\n";
                return -1;
            }
            return 0;
        }
    }
    std::cout << "[Error] δ�ҵ�Ա��ID=" << empId << std::endl;
    return -1;
}

int ServiceModeImpl::listDeptEmployees(int deptId) {
    bool deptFound = false;
    for (auto& d : departments_) {
        if (d.getId() == deptId) {
            deptFound = true;
            break;
        }
    }
    if (!deptFound) {
        std::cout << "[Error] δ�ҵ�����ID=" << deptId << std::endl;
        return -1;
    }

    bool empty = true;
    for (auto& e : employees_) {
        if (e.getDeptId() == deptId) {
            if (empty) {
                std::cout << "\n=== ����" << deptId << "��Ա���б� ===\n";
                empty = false;
            }
            std::cout << "ID��" << e.getId() << "  ������" << e.getName() << "  �Ա�" << (e.isMale() ? "��" : "Ů") << "  ���䣺" << e.getAge() << "\n";
        }
    }
    if (empty) {
        std::cout << "[Info] �ò�����û��Ա��.\n";
    }
    return 0;
}

int ServiceModeImpl::listAllEmployees() {
    if (employees_.empty()) {
        std::cout << "[Info] ��ǰû���κ�Ա��.\n";
        return 0;
    }

    std::cout << "\n=== ȫ��Ա���б� ===\n";
    for (auto& e : employees_) {
        std::cout << "DeptID��" << e.getDeptId() << "  EmpID��" << e.getId() << "  ������" << e.getName() << "  �Ա�" << (e.isMale() ? "��" : "Ů") << "  ���䣺" << e.getAge() << "\n";
    }
    return 0;
}
