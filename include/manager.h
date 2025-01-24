#pragma once

#include <string>

class Manager {
public:
    Manager() = default;
    Manager(int id, const std::string& name, const std::string& password);

    int getId() const;
    const std::string& getName() const;
    const std::string& getPassword() const;

    void setName(const std::string& name);
    void setPassword(const std::string& password);

private:
    int id_{ 0 };
    std::string name_;
    std::string password_;
};
