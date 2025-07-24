/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/24 17:11:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
  ScavTrap clap("Horst");

  clap.attack("Kalle");
  clap.beRepaired(15);
  clap.takeDamage(25);
  clap.beRepaired(1);
  clap.beRepaired(100);
  clap.attack("Kalle");
  clap.guardGate();

  return (0);
}
