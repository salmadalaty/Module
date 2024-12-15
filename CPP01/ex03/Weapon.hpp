#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);                                            
    const std::string getType() const;     
    void setType(const std::string newType); 
};

#endif
