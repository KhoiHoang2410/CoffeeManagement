//
//  Admin.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#ifndef Admin_hpp
#define Admin_hpp

#include "Material/MaterialRepository.hpp"
#include "Product/ProductRepository.hpp"

class Admin {
private:
    MaterialRepository materialRepo;
    ProductRepository productRepo;
public:
};

#endif /* Admin_hpp */
