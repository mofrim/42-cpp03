/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 19:46:16 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "utils.hpp"

#include <iostream>

int main()
{
  FragTrap clap("Horst");

  newline();

  clap.attack("Kalle");
  clap.beRepaired(15);
  clap.takeDamage(25);
  clap.beRepaired(1);
  clap.beRepaired(100);
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.highFivesGuys();

  newline();

  FragTrap clapfrag = clap;

  newline();

  clapfrag.attack("Kalle");
  clapfrag.beRepaired(15);
  clapfrag.takeDamage(25);
  clapfrag.beRepaired(1);
  clapfrag.beRepaired(100);
  clapfrag.attack("Kalle");
  clapfrag.attack("Kalle");
  clapfrag.highFivesGuys();

  newline();

  FragTrap fraggy("Moep");

  newline();
  
  fraggy.highFivesGuys();
  fraggy.beRepaired(0);

  newline();

  return (0);
}
