//
//  Date.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../Include/Date.hpp"

#include <ctime>

Date::Date() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    this->dd = ltm->tm_mday;
    this->mm = ltm->tm_mon;
    this->yy = ltm->tm_year;
}

Date::Date(int day, int month, int year) {
    this->dd = day;
    this->mm = month;
    this->yy = year;
}

int Date::Day() const {
    return this->dd;
}

int Date::Month() const {
    return this->mm;
}

int Date::Year() const {
    return this->yy;
}

void Date::Output(ostream& out) const {
    out << dd << " " << mm << " " << yy << endl;
}

ostream& operator <<(ostream& out, const Date& src) {
    src.Output(out);
    return out;
}

