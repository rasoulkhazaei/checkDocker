#include "../include/hw2.h"
#include <iostream>
#include <algorithm>

User::User(std::string name, std::string pass, std::string mail) : username(name), password(pass), email(mail)
{
}

User::~User()
{
}

Login::Login()
{
}

void Login::readFile(std::string path)
{

}

bool Login::checkUsername(std::string &new_username)
{
    auto it = std::find_if(users.begin(), users.end(), [this, new_username](User *user){
        return user->username == new_username;
    });
    if (it == users.end())
        return true;
    return false;
}

bool Login::checkEmail(std::string &new_email)
{
    auto it = std::find_if(users.begin(), users.end(), [new_email](User *user){
        return user->email == new_email;
    });
    if (it == users.end())
        return true;
    return false;
}

void Login::changeUsername(std::string username, std::string newUsername)
{
    User *user = getUser(username);
    user->username = newUsername;
}

void Login::changePassword(std::string username, std::string newPassword)
{
    User* user = getUser(username);
    user->password = newPassword;
}

void Login::changeMail(std::string username, std::string newMail)
{
    User *tmp = getUser(username);
    tmp->email = newMail;
}

void Login::registerUser(std::string username, std::string password, std::string email)
{
    if (checkEmail(email) && checkUsername(username)) {
        User *tmp = new User(username, password, email);
        users.push_back(tmp);
        // std::cout << "user added" << std::endl;
    }
    else {
        // std::cout << "user exists" << std::endl;
    }
}

void Login::loginUser(std::string username, std::string password)
{
    auto it = std::find_if(users.begin(), users.end(), [username, password](User* user){
        return user->username == username && user->password == password;
    });
    if (it != users.end())
        LoginedUsers.push_back(*it);
}

void Login::removeUser(std::string username)
{
    auto it = std::remove_if(users.begin(), users.end(), [username](User *user) {
        return user->username == username;
    });
    users.erase(it, users.end());
    for (auto *user : users){
        std::cout << user->username << std::endl;
    }
    auto it2 = std::remove_if(LoginedUsers.begin(), LoginedUsers.end(), [username](User *user) {
        return user->username == username;
    });
    LoginedUsers.erase(it2, LoginedUsers.end());
}

User* Login::getUser (std::string username)
{
    auto it = std::find_if(users.begin(), users.end(), [username](User *user){
        return user->username == username;
    });
    if (it == users.end())
        return nullptr;
    return *it;
}

Login::~Login()
{
}