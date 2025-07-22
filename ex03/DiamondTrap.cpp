/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:57:31 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/22 19:53:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "utils.hpp"

#include <iostream>

// FIXME: think through if this is already logically sound

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
  dbg_msg("DiamondTrap", "Default constructor called.");

  _name             = "Elon";
  FragTrap::_hp     = 100;
  ScavTrap::_energy = 50;
  FragTrap::_dmg    = 30;
}

DiamondTrap::DiamondTrap(const std::string& name):
  ClapTrap(name), ScavTrap(name), FragTrap(name)
{
  dbg_msg("DiamondTrap", "Default constructor called.");

  _name           = name;
  ClapTrap::_name = name + "_clap_name";
  _hp             = FragTrap::_hp;
  _energy         = ScavTrap::_energy;
  _dmg            = FragTrap::_dmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
  ClapTrap(other), ScavTrap(other), FragTrap(other)
{
  dbg_msg("DiamondTrap", "Default constructor called.");
  _name           = other._name;
  ClapTrap::_name = other._name + "_clap_name";
  _hp             = other.FragTrap::_hp;
  _energy         = other.ScavTrap::_hp;
  _dmg            = other.FragTrap::_dmg;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
  dbg_msg("DiamondTrap", "Default assingment constructor called.");
  if (this != &other)
  {
    _name           = other._name;
    ClapTrap::_name = other.ClapTrap::_name;
    _hp             = other.FragTrap::_hp;
    _energy         = other.ScavTrap::_hp;
    _dmg            = other.FragTrap::_dmg;
  }
  return (*this);
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::whoAmI()
{
  std::cout << "_DiamondTrap (" + _name + ") " << "i am " << _name << " and "
            << ClapTrap::_name << " at the same time \\o/" << std::endl;
}
