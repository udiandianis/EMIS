#pragma once

#include "service_view.h"

class ServiceViewImpl : public ServiceView {
public:
    ServiceViewImpl() = default;
    ~ServiceViewImpl() override = default;

    void menu() override;
    void setServiceCtrl(ServiceCtrl* ctrl) override;

private:
    ServiceCtrl* ctrl_{ nullptr };
};
