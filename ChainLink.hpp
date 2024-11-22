#ifndef CHAINLINK_H
#define CHAINLINK_H
#include <string>

class ChainLink {
private:
    std::string color;

public:
    ChainLink(){
        this->color = "None Provided. Default Constructor.";
    }

    ChainLink(std::string color) {
        this->color = color;
    }

    std::string get_color() {
        return this-> color;
    }
};

#endif // CHAINLINK_H