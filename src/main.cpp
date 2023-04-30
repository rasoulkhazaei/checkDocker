#include "gtest/gtest.h"
#include "../include/hw2.h"


#include <iostream>

int main (int argc, char *argv[]) {

    if (false) // make false to run unit tests  
    { 
        // debug section 
        Login l;
        l.registerUser("ali", "123456", "ali@gmail.com");
        
        l.registerUser("rasoul", "123456", "rasoul.kh41@gmail.com");
        l.removeUser("rasool");
        for (User* user : l.users){
            std::cout << user->username << std::endl;
        }
    } 
    else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << RUN_ALL_TESTS() << std::endl;
    }
}