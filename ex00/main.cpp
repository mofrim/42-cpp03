/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 19:07:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"

#include <iostream>

int main(void)
{
  ClapTrap clap0("Horst");

  newline();

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

  newline();

  ClapTrap clap1("Hoinz");

  newline();

  clap1.attack("Horst");
  clap1.beRepaired(0);
  clap1.takeDamage(0);

  newline();

  clap1 = clap0;

  newline();

  clap1.attack("Horst");

  newline();

  ClapTrap clap2(clap1);

  newline();

  clap2.takeDamage(1000);
  clap2.beRepaired(1000);
  clap2.takeDamage(1000);
  
  newline();

  return (0);
}
