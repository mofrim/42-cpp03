/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 17:55:28 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int main(void)
{
  ClapTrap clap0("Horst");

  std::cout << std::endl;

  clap0.attack("Kalle");
  clap0.beRepaired(15);
  clap0.takeDamage(25);
  clap0.beRepaired(1);
  clap0.beRepaired(100);
  clap0.attack("Kalle");
  clap0.attack("Kalle");
  clap0.attack("Kalle");
  clap0.attack("Kalle");
  clap0.attack("Kalle");
  clap0.attack("Kalle");
  clap0.attack("Kalle");

  std::cout << std::endl;

  ClapTrap clap1("Hoinz");

  std::cout << std::endl;

  clap1.attack("Horst");
  clap1.beRepaired(0);
  clap1.takeDamage(0);

  std::cout << std::endl;

  clap1 = clap0;

  std::cout << std::endl;

  clap1.attack("Horst");

  std::cout << std::endl;

  ClapTrap clap2(clap1);

  std::cout << std::endl;

  clap2.takeDamage(1000);
  clap2.beRepaired(1000);
  clap2.takeDamage(1000);

  return (0);
}
