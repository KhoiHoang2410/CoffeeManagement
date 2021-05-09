//
//  ObjectManager.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef ObjectManager_hpp
#define ObjectManager_hpp

class ObjectManager {
private:
    static int inline nextID = 1;
public:
    static int generateNewID();
};

#endif /* ObjectManager_hpp */
