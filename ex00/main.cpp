/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/21 08:30:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap clap("Horst");

  clap.attack("Kalle");
  clap.beRepaired(-15);
  clap.takeDamage(25);
  clap.beRepaired(1);
  clap.beRepaired(100);
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");
  clap.attack("Kalle");

  return (0);
}
