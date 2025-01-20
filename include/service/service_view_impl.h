#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "service_view.h"
#include "service_ctrl.h"

class ServiceViewImpl : public ServiceView {
private:
    ServiceCtrl* controller;

public:
    explicit ServiceViewImpl(ServiceCtrl* ctrl);

    void showDepartmentList() override;
    void showEmployeeList(int departmentId) override;
    void showAddDepartmentResult(bool success, const std::string& departmentName) override;
    void showDeleteDepartmentResult(bool success, int departmentId) override;
    void showAddEmployeeResult(bool success, const std::string& employeeName) override;
    void showDeleteEmployeeResult(bool success, int employeeId) override;
};

#endif // SERVICE_VIEW_IMPL_H
