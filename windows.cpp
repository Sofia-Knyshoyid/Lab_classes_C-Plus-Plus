#include <iostream>
using namespace std;

#include "user.h"
#include "windows.h"

#warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym" // po zaimplementowaniu sugeruje usuniecie tej linijki - nie chcemy warningow

// defining static value
size_t Windows::activated_systems_ = 0;
std::vector<User> Windows::users_;


Windows::Windows() : version_("11") {
    cout << "Windows " << version_ << endl;
    ++activated_systems_;
}

Windows::Windows(string ver) : version_(ver) {
    cout << "Windows " << version_ << endl;
    ++activated_systems_;
}


Windows::~Windows() {
    cout << "Windows " << version_ << endl;
    --activated_systems_;
}

// getter for version_
string Windows::version() const {
    return version_;
}

// static method
size_t Windows::activated_systems() {
    return activated_systems_;
}

// adding a user and returning user id
size_t Windows::add_user(string user_name, string password){
    User new_user = User{user_name, password};
    users_.push_back(new_user);
    return users_.size() - 1;
}

vector<User> Windows::users_getter() {
    return users_;
}

// gets user id, returns user
User Windows::user(int user_id) const{
    return users_[user_id];
}

// returns path to home directory of the specific user
string Windows::user_home_directory(int user_id) const{
    string username = users_[user_id].user_name_;
    return "C:\\Users\\" + username;
}
