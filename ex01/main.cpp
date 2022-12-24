/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:15:29 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/23 22:49:47 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	ScavTrap c("amine");
	ScavTrap d("diouane");

	a.attack("B");
	a.takeDamage(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(10);

	std::cout << "----------------" << std::endl;
	
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	c.guardGate();
	d.guardGate();
	return 0;
}
