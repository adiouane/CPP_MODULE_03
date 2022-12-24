/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:15:29 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/24 16:34:56 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	FragTrap c("amine");
	FragTrap d("diouane");
	ScavTrap x("ok");

	std::cout << "----------------" << std::endl;
	a.attack("B");
	a.takeDamage(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(10);
	std::cout << "----------------" << std::endl;

	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	std::cout << "----------------" << std::endl;
	
	c.attack("diouane");
	c.takeDamage(10);
	c.beRepaired(8);
	c.highFivesGuys();

	std::cout << "----------------" << std::endl;
	d.attack("amine");
	d.takeDamage(6);
	d.beRepaired(9);
	d.highFivesGuys();
	std::cout << "----------------" << std::endl;
	x.attack("anonymous");
	x.takeDamage(9);
	x.beRepaired(20);
	x.guardGate();
	std::cout << "----------------" << std::endl;
	return 0;
}
