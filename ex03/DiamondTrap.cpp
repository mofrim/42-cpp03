/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:57:31 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 07:06:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "utils.hpp"

#include <iomanip>
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
  this->_name          = "noname";
  this->FragTrap::_hp  = 100;
  this->ScavTrap::_nrg = 50;
  this->FragTrap::_dmg = 30;
  this->_msgPrefix     = get_prefix("DiamondTrap", this->_name);
  dbg_msg("DiamondTrap " + this->_name, "Default constructor called.");
}

DiamondTrap::DiamondTrap(const std::string& name):
  ClapTrap(name), ScavTrap(name), FragTrap(name)
{
  this->_name           = name;
  this->ClapTrap::_name = name + "_clap_name";
  this->_hp             = FragTrap::_hp;
  this->_nrg            = ScavTrap::_nrg;
  this->_dmg            = FragTrap::_dmg;
  this->_msgPrefix      = get_prefix("DiamondTrap", this->_name);
  dbg_msg("DiamondTrap " + this->_name, "Default constructor called.");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
  ClapTrap(other), ScavTrap(other), FragTrap(other)
{
  this->_name           = other._name;
  this->ClapTrap::_name = other._name + "_clap_name";
  this->_hp             = other.FragTrap::_hp;
  this->_nrg            = other.ScavTrap::_nrg;
  this->_dmg            = other.FragTrap::_dmg;
  this->_msgPrefix      = other._msgPrefix;
  dbg_msg("DiamondTrap " + this->_name, "Default constructor called.");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
  dbg_msg("DiamondTrap " + this->_name,
          "Default assingment constructor called.");
  if (this != &other)
  {
    this->_name           = other._name;
    this->ClapTrap::_name = other.ClapTrap::_name;
    this->_hp             = other.FragTrap::_hp;
    this->_nrg            = other.ScavTrap::_nrg;
    this->_dmg            = other.FragTrap::_dmg;
    this->_msgPrefix      = other._msgPrefix;
  }
  return (*this);
}

DiamondTrap::~DiamondTrap()
{
  dbg_msg("DiamondTrap " + this->_name, "Destructor called.");
}

void DiamondTrap::whoAmI()
{
  std::cout << this->_msgPrefix << "i am " << _name << " and "
            << ClapTrap::_name << " at the same time \\o/" << std::endl;
  printStats();
}

void DiamondTrap::printStats() const
{
  std::cout << std::setw(this->_msgPrefix.length()) << " ";
  std::cout << ">>> " << this->_name << "'s stats: {nrg: " << this->_nrg
            << ", hp: " << this->_hp << ", dmg: " << this->_dmg << "}"
            << std::endl;
}
