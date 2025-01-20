#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"
#include "service_ctrl.h"
#include "service_view.h"

class ServiceModeImpl : public ServiceMode {
private:
    ServiceCtrl* controller;
    ServiceView* viewer; // ÉùÃ÷ viewer ³ÉÔ±

public:
    ServiceModeImpl(ServiceCtrl* ctrl, ServiceView* view);
    void displayMenu() override;
    void handleInput() override;
};

#endif // SERVICE_MODE_IMPL_H
