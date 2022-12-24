/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:58:42 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/24 17:33:11 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::~FragTrap(void){
    std::cout << "FragTrap (" << this->Name  << ") Destructuer called." << std::endl;
};

FragTrap::FragTrap(void){
    std::cout << "FragTrap " << "Defualt Constructuer called." << std::endl;
    this->Name = "Default";
    this->Hitpoint = 100;
    this->Energy = 100;
    this->AttackDamage = 30;
};

FragTrap::FragTrap(std::string name)
{
    this->Name = name;
    this->Hitpoint = 100;
    this->Energy = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap (" << name << ") Constructuer With parameter called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj){
    this->Name = obj.Name;
    this->Energy = obj.Energy;
    this->AttackDamage = obj.AttackDamage;
    this->Hitpoint = obj.Hitpoint;
    std::cout << "FragTrap (" << this->Name << ") Copy Constructuer called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj){

    std::cout << "FragTrap (" << this->Name << ") Copy Assignment operator called." << std::endl;
    this->Name = obj.Name;
    this->Energy = obj.Energy;
    this->AttackDamage = obj.AttackDamage;
    this->Hitpoint = obj.Hitpoint;
    return (*this);
}

/*----member function attack----*/

void FragTrap::attack(const std::string& target){
    if (this->Energy <= 0 || this->Hitpoint <= 0)
        std::cout << "FragTrap (" << this->Name << ") is dead." << std::endl;
    else
    {
        std::cout << "FragTrap (" << this->Name << ") attack (" << target << "), causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->Energy -= 1;
    }
}

/*----member function takeDamage----*/

void FragTrap::takeDamage(unsigned int amount){
    if (this->Hitpoint < amount)
    {
        std::cout << "FragTrap (" << this->Name  << ") he is already dead." << std::endl;
        return ;
    }else{
        this->Hitpoint -= amount;
        std::cout << "FragTrap (" << this->Name << ") take (" << amount << ") damage, he have (" << this->Hitpoint << ") hitpoint left." << std::endl;
    }
}

/*----member function beRepaired----*/

void FragTrap::beRepaired(unsigned int amount){
    if (this->Hitpoint <= 0 || this->Energy <= 0)
    {
        std::cout << "FragTrap (" << this->Name << ") is already dead." << std::endl;
        return ;
    }else{
        this->Hitpoint += amount;
        std::cout << "FragTrap (" << this->Name << ") is repaired, he have (" << this->Hitpoint << ") hitpoint left." << std::endl;
    }
}


void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap (" << this->Name << ") give high five to everyone." << std::endl;
}
