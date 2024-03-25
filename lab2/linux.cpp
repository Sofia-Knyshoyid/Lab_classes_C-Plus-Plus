#include <iostream>
using namespace std;

#include "user.h"
#include "linux.h"

#warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym" // po zaimplementowaniu sugeruje usuniecie tej linijki - nie chcemy warningow

// defining static value
size_t Linux::open_source_sympathizers_ = 0;
std::vector<User> Linux::users_;


Linux::Linux() : distribution_("Ubuntu") {
    cout << "+" << distribution_ << endl;
    open_source_sympathizers_++;
}

Linux::Linux(string distr) : distribution_(distr) {
    cout << "+" << distribution_ << endl;
    open_source_sympathizers_++;
}


Linux::~Linux() {
    cout << "~" << distribution_ << endl;
    open_source_sympathizers_--;
}

// getter for distribution_
string Linux::distribution() const {
    return distribution_;
}

// static method
size_t Linux::open_source_sympathizers() {
    return open_source_sympathizers_;
}

// adding a user and returning user id
size_t Linux::add_user(string user_name, string password){
    User new_user = User{user_name, password};
    users_.push_back(new_user);
    return users_.size() - 1;
}

vector<User> Linux::users_getter() {
    return users_;
}

// gets user id, returns user
User Linux::user(int user_id) const{
    return users_[user_id];
}

// returns path to home directory of the specific user
string Linux::user_home_directory(int user_id) const{
    string username = users_[user_id].user_name_;
    return "/home/" + username + "/";
}

// getter and setter for graphic_environment_
optional<std::string> Linux::graphic_environment() const {
    return graphic_environment_;
}

void Linux::set_graphic_environment(optional<std::string> str) {
    graphic_environment_ = str;
}