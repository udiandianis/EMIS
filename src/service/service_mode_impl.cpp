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
        // 文件不存在
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

        // 读取该部门下的员工
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
        std::cout << "[Error] 打开 " << EMIS::g_serviceDataFile << " 失败.\n";
        return -1;
    }

    // 根据 departments_ 写出部门信息及对应员工
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

// 部门
int ServiceModeImpl::addDepartment(const std::string& name) {
    int newId = getNewDeptId();
    if (newId < 0) {
        std::cout << "[Error] 无法生成新的部门ID.\n";
        return -1;
    }
    departments_.emplace_back(newId, name, 0);
    std::cout << "[OK] 已添加部门: ID=" << newId << ", 名称=" << name << std::endl;
    return 0;
}

int ServiceModeImpl::delDepartment(int deptId) {
    for (auto it = departments_.begin(); it != departments_.end(); ++it) {
        if (it->getId() == deptId) {
            // 同时删除该部门下所有员工
            for (auto empIt = employees_.begin(); empIt != employees_.end();) {
                if (empIt->getDeptId() == deptId) {
                    empIt = employees_.erase(empIt);
                }
                else {
                    ++empIt;
                }
            }

            departments_.erase(it);
            std::cout << "[OK] 已删除部门ID=" << deptId << "及其员工.\n";
            return 0;
        }
    }
    std::cout << "[Error] 未找到ID=" << deptId << "的部门.\n";
    return -1;
}

int ServiceModeImpl::listDepartment() {
    if (departments_.empty()) {
        std::cout << "[Info] 当前没有任何部门.\n";
        return 0;
    }
    std::cout << "\n=== 部门列表 ===\n";
    for (auto& dept : departments_) {
        std::cout << "部门ID：" << dept.getId() << "  名称：" << dept.getName() << "  员工数：" << dept.getEmpCount() << "\n";
    }
    return 0;
}

// 员工
int ServiceModeImpl::addEmployee(const std::string& name, bool isMale, int age, int deptId) {
    // 检查部门是否存在
    bool found = false;
    for (auto& d : departments_) {
        if (d.getId() == deptId) {
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "[Error] 部门ID=" << deptId << " 不存在.\n";
        return -1;
    }

    int newId = getNewEmpId();
    if (newId < 0) {
        std::cout << "[Error] 生成员工ID失败.\n";
        return -1;
    }
    employees_.emplace_back(newId, name, isMale, age, deptId);

    // 部门人数 +1
    for (auto& d : departments_) {
        if (d.getId() == deptId) {
            d.setEmpCount(d.getEmpCount() + 1);
            break;
        }
    }
    std::cout << "[OK] 已添加员工: ID：" << newId << ", 姓名：" << name << ", 部门：" << deptId << std::endl;
    return 0;
}

int ServiceModeImpl::delEmployee(int empId) {
    for (auto it = employees_.begin(); it != employees_.end(); ++it) {
        if (it->getId() == empId) {
            // 部门人数 -1
            for (auto& d : departments_) {
                if (d.getId() == it->getDeptId()) {
                    d.setEmpCount(d.getEmpCount() - 1);
                    break;
                }
            }
            employees_.erase(it);
            std::cout << "[OK] 已删除员工ID=" << empId << std::endl;
            return 0;
        }
    }
    std::cout << "[Error] 未找到ID=" << empId << "的员工.\n";
    return -1;
}

int ServiceModeImpl::modifyEmployee(int empId) {
    for (auto& e : employees_) {
        if (e.getId() == empId) {
            // 修改选项
            std::cout << "请选择要修改的字段:\n"
                << "1. 姓名\n"
                << "2. 性别\n"
                << "3. 年龄\n"
                << "4. 部门ID\n"
                << "0. 取消\n"
                << "输入选项: ";
            int opt = 0;
            std::cin >> opt;

            switch (opt) {
            case 1: {
                std::string newName;
                std::cout << "请输入新姓名: ";
                std::cin >> newName;
                e.setName(newName);
                std::cout << "[OK] 修改成功.\n";
                break;
            }
            case 2: {
                char c = 0;
                std::cout << "请输入(m=男, w=女): ";
                std::cin >> c;
                e.setIsMale(c == 'm');
                std::cout << "[OK] 修改成功.\n";
                break;
            }
            case 3: {
                int newAge = 0;
                std::cout << "请输入新年龄: ";
                std::cin >> newAge;
                e.setAge(newAge);
                std::cout << "[OK] 修改成功.\n";
                break;
            }
            case 4: {
                int oldDept = e.getDeptId();
                int newDept = 0;
                std::cout << "请输入新部门ID: ";
                std::cin >> newDept;

                // 检查新部门是否存在
                bool deptFound = false;
                for (auto& d : departments_) {
                    if (d.getId() == newDept) {
                        deptFound = true;
                        break;
                    }
                }
                if (!deptFound) {
                    std::cout << "[Error] 部门不存在.\n";
                    return -1;
                }

                // 原部门人数 -1
                for (auto& d : departments_) {
                    if (d.getId() == oldDept) {
                        d.setEmpCount(d.getEmpCount() - 1);
                        break;
                    }
                }
                // 新部门人数 +1
                for (auto& d : departments_) {
                    if (d.getId() == newDept) {
                        d.setEmpCount(d.getEmpCount() + 1);
                        break;
                    }
                }
                e.setDeptId(newDept);
                std::cout << "[OK] 修改成功.\n";
                break;
            }
            case 0:
                std::cout << "取消.\n";
                return 0;
            default:
                std::cout << "[Error] 无效操作.\n";
                return -1;
            }
            return 0;
        }
    }
    std::cout << "[Error] 未找到员工ID=" << empId << std::endl;
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
        std::cout << "[Error] 未找到部门ID=" << deptId << std::endl;
        return -1;
    }

    bool empty = true;
    for (auto& e : employees_) {
        if (e.getDeptId() == deptId) {
            if (empty) {
                std::cout << "\n=== 部门" << deptId << "的员工列表 ===\n";
                empty = false;
            }
            std::cout << "ID：" << e.getId() << "  姓名：" << e.getName() << "  性别：" << (e.isMale() ? "男" : "女") << "  年龄：" << e.getAge() << "\n";
        }
    }
    if (empty) {
        std::cout << "[Info] 该部门下没有员工.\n";
    }
    return 0;
}

int ServiceModeImpl::listAllEmployees() {
    if (employees_.empty()) {
        std::cout << "[Info] 当前没有任何员工.\n";
        return 0;
    }

    std::cout << "\n=== 全部员工列表 ===\n";
    for (auto& e : employees_) {
        std::cout << "DeptID：" << e.getDeptId() << "  EmpID：" << e.getId() << "  姓名：" << e.getName() << "  性别：" << (e.isMale() ? "男" : "女") << "  年龄：" << e.getAge() << "\n";
    }
    return 0;
}
