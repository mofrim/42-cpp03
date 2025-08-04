/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 07:02:17 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "utils.hpp"

int main(void)
{
  DiamondTrap clap("Horst");

  newline();

  clap.attack("Kalle");
  clap.beRepaired(15);
  clap.takeDamage(25);
  clap.beRepaired(1);
  clap.beRepaired(100);
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.highFivesGuys();
  clap.guardGate();
  clap.whoAmI();

  newline();

  FragTrap frag("at");

  newline();

  frag = FragTrap("aaaat");

  newline();

  frag.attack("Chris");

  newline();

  return (0);
}
