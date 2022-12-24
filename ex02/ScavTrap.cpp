/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:12:32 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/24 17:33:25 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap (" << this->Name  << ") Destructuer called." << std::endl;
};

ScavTrap::ScavTrap(void){
    std::cout << "ScavTrap " << "Defualt Constructuer called." << std::endl;
    this->Name = "Default";
    this->Hitpoint = 100;
    this->Energy = 50;
    this->AttackDamage = 20;
};

ScavTrap::ScavTrap(std::string name)
{
    this->Name = name;
    this->Hitpoint = 100;
    this->Energy = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap (" << name << ") Constructuer With parameter called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj){
    this->Name = obj.Name;
    this->Energy = obj.Energy;
    this->AttackDamage = obj.AttackDamage;
    this->Hitpoint = obj.Hitpoint;
    std::cout << "ScavTrap (" << this->Name << ") Copy Constructuer called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj){

    std::cout << "ScavTrap (" << this->Name << ") Copy Assignment operator called." << std::endl;
    this->Name = obj.Name;
    this->Energy = obj.Energy;
    this->AttackDamage = obj.AttackDamage;
    this->Hitpoint = obj.Hitpoint;
    return (*this);
}

void ScavTrap::attack(const std::string& target){
    if (this->Energy <= 0 || this->Hitpoint <= 0)
        std::cout << "ScavTrap (" << this->Name << ") is dead." << std::endl;
    else
    {
        std::cout << "ScavTrap (" << this->Name << ") attack (" << target << "), causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->Energy -= 1;
    }
}

/*----member function takeDamage----*/

void ScavTrap::takeDamage(unsigned int amount){
    if (this->Hitpoint < amount)
    {
        std::cout << "ScavTrap (" << this->Name  << ") he is already dead." << std::endl;
        return ;
    }else{
        this->Hitpoint -= amount;
        std::cout << "ScavTrap (" << this->Name << ") take (" << amount << ") damage, he have (" << this->Hitpoint << ") hitpoint left." << std::endl;
    }
}

/*----member function beRepaired----*/

void ScavTrap::beRepaired(unsigned int amount){
    if (this->Hitpoint <= 0 || this->Energy <= 0)
    {
        std::cout << "ScavTrap (" << this->Name << ") is already dead." << std::endl;
        return ;
    }else{
    this->Hitpoint += amount;
    std::cout << "ScavTrap (" << this->Name << ") is repaired, he have (" << this->Hitpoint << ") hitpoint left." << std::endl;
    }
}

/*
    member function guardGate
*/
void ScavTrap::guardGate(){
    std::cout << "ScavTrap (" << this->Name << ") Guard Gate called." << std::endl;
};
