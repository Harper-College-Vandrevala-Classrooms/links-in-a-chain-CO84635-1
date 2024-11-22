#include <iostream>
#include "Chainlink.hpp"
#include "LinkedList.hpp"
#include <cassert>
#include <stdexcept>

int main() {
    //Empty LinkedList:
    {
        LinkedList links_empty;
        bool exception_occured = false;
        try {
            links_empty.get(0);
        } catch (std::out_of_range) {
            exception_occured = true;
        }
        assert(exception_occured);
    }
    
    //Testing One Link:
    {
        LinkedList links_one;
        ChainLink blue_link("Blue");
        links_one.insertAtTail(blue_link);

        assert(links_one.get(0).get_color() == "Blue");
    }
    
    //Testing Multiple Links:
    {
    
        LinkedList links_multiple;
        ChainLink green_link("Green");
        ChainLink red_link("Red");
        ChainLink blue_link("Blue");

        links_multiple.insertAtTail(green_link);
        links_multiple.insertAtTail(red_link);
        links_multiple.insertAtTail(blue_link);

        assert(links_multiple.get(0).get_color() == "Green");
        assert(links_multiple.get(1).get_color() == "Red");
        assert(links_multiple.get(2).get_color() == "Blue");
    }
    
    //Testing OutOfBounds
    {
        LinkedList links_out_of_bounds;
        ChainLink green_link("Green");
        links_out_of_bounds.insertAtTail(green_link);
        bool exception_occured = false;
        try {
            links_out_of_bounds.get(1);
        } catch (std::out_of_range) {
            exception_occured = true;
        }
        assert(exception_occured);
    }

    std::cout << "All of the test have passed! Congrats!" << std::endl;
    return 0;
}
