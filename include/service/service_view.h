#ifndef SERVICE_VIEW_H
#define SERVICE_VIEW_H

#include <string>

class ServiceView {
public:
    virtual void showDepartmentList() = 0;
    virtual void showEmployeeList(int departmentId) = 0;
    virtual void showAddDepartmentResult(bool success, const std::string& departmentName) = 0;
    virtual void showDeleteDepartmentResult(bool success, int departmentId) = 0;
    virtual void showAddEmployeeResult(bool success, const std::string& employeeName) = 0;
    virtual void showDeleteEmployeeResult(bool success, int employeeId) = 0;
    virtual ~ServiceView() = default;
};

#endif // SERVICE_VIEW_H
