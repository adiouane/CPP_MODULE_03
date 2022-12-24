/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:15:31 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/24 18:02:36 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap (" << this->Name << ") Destructuer called." << std::endl;
};

ClapTrap::ClapTrap(void){
    std::cout << "ClapTrap " << this->Name  << " Defualt Constructuer called." << std::endl;
    this->Name = "Default";
    this->Hitpoint = 10;
    this->Energy = 10;
    this->AttackDamage = 0;
};

ClapTrap::ClapTrap(std::string name)
{
    this->Name = name;
    this->Energy = 10;
    this->Hitpoint = 10;
    this->AttackDamage = 0;
    std::cout << "ClapTrap (" << name << ") Constructuer With parameter called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj){
    this->Name = obj.Name;
    this->Energy = obj.Energy;
    this->AttackDamage = obj.AttackDamage;
    this->Hitpoint = obj.Hitpoint;
    std::cout << "ClapTrap (" << this->Name << ") Copy costructuer called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj){

    std::cout << "ClapTrap (" << this->Name << ") Copy Assignment operator called." << std::endl;
    this->Name = obj.Name;
    this->Energy = obj.Energy;
    this->AttackDamage = obj.AttackDamage;
    this->Hitpoint = obj.Hitpoint;
    return (*this);
}

/*----member function attack----*/

void ClapTrap::attack(const std::string& target){
    if (this->Energy <= 0 || this->Hitpoint <= 0)
        std::cout << "ClapTrap (" << this->Name << ") is dead." << std::endl;
    else
    {
        std::cout << "ClapTrap (" << this->Name << ") attack (" << target << "), causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->Energy -= 1;
    }
}

/*----member function takeDamage----*/

void ClapTrap::takeDamage(unsigned int amount){
    if (this->Hitpoint < amount)
    {
        std::cout << "ClapTrap (" << this->Name  << ") he is already dead." << std::endl;
        return ;
    }
    this->Hitpoint -= amount;
    std::cout << "ClapTrap (" << this->Name << ") take (" << amount << ") damage, he have (" << this->Hitpoint << ") hitpoint left." << std::endl;
}

/*----member function beRepaired----*/

void ClapTrap::beRepaired(unsigned int amount){
    if (this->Hitpoint <= 0 || this->Energy <= 0)
    {
        std::cout << "ClapTrap (" << this->Name << ") he is already dead." << std::endl;
        return ;
    }
    this->Hitpoint += amount;
    std::cout << "ClapTrap (" << this->Name << ") is repaired, he have (" << this->Hitpoint << ") hitpoint left." << std::endl;
}
