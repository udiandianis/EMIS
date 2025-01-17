#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class Manager {
public:
    Manager(int id, const std::string& username, const std::string& password)
        : id(id), username(username), password(password) {}

    // ������
    int getId() const { return id; }
    const std::string& getUsername() const { return username; }
    const std::string& getPassword() const { return password; }

    // �޸����������Ҫ�����Լ������ú�����
    void setId(int newId) { id = newId; }
    void setUsername(const std::string& name) { username = name; }
    void setPassword(const std::string& pass) { password = pass; }

private:
    int id;
    std::string username;
    std::string password;
};

#endif // MANAGER_H
