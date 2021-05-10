//
//  Helper.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Helper_h
#define Helper_h

#include <string>

using namespace std;

string Normalize(string&);

void putError(string classBehaviour, string log);
void putError(string classBehaviour, string log, int code);

#endif /* Helper_h */
