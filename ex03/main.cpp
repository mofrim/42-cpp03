/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/22 20:27:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
  DiamondTrap clap("Horst");

  // clap.attack("Kalle");
  // clap.beRepaired(15);
  // clap.takeDamage(25);
  // clap.beRepaired(1);
  // clap.beRepaired(100);
  // clap.attack("Kalle");
  // clap.attack("Kalle");
  // clap.attack("Kalle");
  // clap.attack("Kalle");
  // clap.highFivesGuys();
  // clap.guardGate();
  // clap.whoAmI();
  
  FragTrap frag("at");
  frag = FragTrap("aaaat");
  frag.attack("Chris");


  return (0);
}
