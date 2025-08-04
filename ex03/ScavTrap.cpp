/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:48:30 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 20:52:32 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "utils.hpp"

#include <iomanip>
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
  this->_name      = "noname";
  this->_hp        = 100;
  this->_nrg       = 50;
  this->_dmg       = 20;
  this->_msgPrefix = get_prefix("ScavTrap", this->_name);
  dbg_msg("ScavTrap " + this->_name, "Default Constructor called.");
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
  this->_name      = name;
  this->_hp        = 100;
  this->_nrg       = 50;
  this->_dmg       = 20;
  this->_msgPrefix = get_prefix("ScavTrap", this->_name);
  dbg_msg("ScavTrap " + this->_name, "Default-Name Constructor called.");
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
  dbg_msg("ScavTrap " + this->_name, "Copy Constructor called.");
  this->_name      = other._name;
  this->_msgPrefix = other._msgPrefix;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  dbg_msg("ScavTrap " + this->_name, "assignment constructor called.");
  if (this != &other)
  {
    this->_name      = other._name;
    this->_hp        = other._hp;
    this->_nrg       = other._nrg;
    this->_dmg       = other._dmg;
    this->_msgPrefix = other._msgPrefix;
  }
  return (*this);
}

ScavTrap::~ScavTrap()
{
  dbg_msg("ScavTrap " + this->_name, "Destructor called.");
};

void ScavTrap::attack(const std::string& target)
{
  if (_hp == -1)
  {
    std::cout << this->_msgPrefix << "trying to attack but already dead!"
              << std::endl;
    printStats();
    return;
  }
  if (this->_nrg == 0)
  {
    std::cout << this->_msgPrefix << "has 0 energy. No more attacks possible!"
              << std::endl;
    printStats();
    return;
  }
  this->_nrg--;
  std::cout << this->_msgPrefix << "attacks " << target << ", causing "
            << this->_dmg << " points of damage!" << std::endl;
  printStats();
}

void ScavTrap::guardGate()
{
  std::cout << this->_msgPrefix << "is now in Gatekeeper mode!" << std::endl;
  printStats();
}

void ScavTrap::printStats() const
{
  std::cout << std::setw(this->_msgPrefix.length()) << " ";
  std::cout << ">>> " << this->_name << "'s stats: {nrg: " << this->_nrg
            << ", hp: " << this->_hp << ", dmg: " << this->_dmg << "}"
            << std::endl;
}
