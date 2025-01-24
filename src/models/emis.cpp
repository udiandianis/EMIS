#include <iostream>
#include <memory>
#include <string>

#include "emis.h"

// Manager 相关
#include "manager_ctrl_impl.h"
#include "manager_mode_impl.h"
#include "manager_view_impl.h"

// Service 相关
#include "service_ctrl_impl.h"
#include "service_mode_impl.h"
#include "service_view_impl.h"

// Tools
#include "tools.h"

namespace EMIS {
    // 在 .cpp 中定义全局变量
    std::string g_managerDataFile{ "managers.dat" };
    std::string g_serviceDataFile{ "services.dat" };
    std::string g_idFile{ "id.dat" };

    int run() {
        // 先加载 ID 信息
        if (loadIds() != 0) {
            std::cout << "[Warn] 加载 " << g_idFile << " 失败，可能是首次使用.\n";
        }

        // 使用智能指针创建管理子系统对象
        auto managerMode = std::make_unique<ManagerModeImpl>();
        managerMode->init();

        auto managerCtrl = std::make_unique<ManagerCtrlImpl>(*managerMode);
        auto managerView = std::make_unique<ManagerViewImpl>();
        managerView->setManagerCtrl(managerCtrl.get());

        // 使用智能指针创建业务子系统对象
        auto serviceMode = std::make_unique<ServiceModeImpl>();
        serviceMode->init();

        auto serviceCtrl = std::make_unique<ServiceCtrlImpl>(*serviceMode);
        auto serviceView = std::make_unique<ServiceViewImpl>();
        serviceView->setServiceCtrl(serviceCtrl.get());

        bool running = true;
        while (running) {
            std::cout << "\n===== 企业信息管理系统菜单 =====\n"
                << "1. 管理子系统\n"
                << "2. 业务子系统\n"
                << "0. 退出系统\n"
                << "================================\n"
                << "请输入选项: ";

            int choice = 0;
            std::cin >> choice;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                continue;
            }

            switch (choice) {
            case 1:
                managerView->menu();
                break;
            case 2:
                serviceView->menu();
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "无效选项，请重新输入.\n";
                break;
            }
        }

        // 退出前保存
        managerMode->save();
        serviceMode->save();
        saveIds();

        std::cout << "系统已退出.\n";
        return 0;
    }
}  // namespace EMIS
