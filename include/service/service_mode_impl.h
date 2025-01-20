#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"
#include "service_ctrl.h"

class ServiceModeImpl : public ServiceMode {
private:
    ServiceCtrl* controller;

public:
    explicit ServiceModeImpl(ServiceCtrl* ctrl);
    void displayMenu() override;
    void handleInput() override;
};

#endif // SERVICE_MODE_IMPL_H
