/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:48:30 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/24 21:11:57 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "utils.hpp"

#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
  dbg_msg("ScavTrap " + this->_name, "Default constructor called.");
  this->_name       = "noname";
  this->_hp         = 100;
  this->_energy     = 50;
  this->_dmg        = 20;
  this->_ScavPrefix = "_ScavTrap_ (" + this->_name + ") ";
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
  dbg_msg("ScavTrap " + this->_name, "Default-Name constructor called.");
  this->_name       = name;
  this->_hp         = 100;
  this->_energy     = 50;
  this->_dmg        = 20;
  this->_ScavPrefix = "_ScavTrap_ (" + this->_name + ") ";
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
  dbg_msg("ScavTrap " + this->_name, "Copy constructor called.");
  this->_name = other._name;
  this->_ScavPrefix = other._ScavPrefix;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  dbg_msg("ScavTrap " + this->_name, "assignment constructor called.");
  if (this != &other)
  {
    this->_name       = other._name;
    this->_hp         = other._hp;
    this->_energy     = other._energy;
    this->_dmg        = other._dmg;
    this->_ScavPrefix = other._ScavPrefix;
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
    std::cout << this->_ScavPrefix << "already dead!" << std::endl;
    return;
  }
  if (this->_energy == 0)
  {
    std::cout << this->_ScavPrefix << "has 0 energy. No more attacks possible!"
              << std::endl;
    return;
  }
  this->_energy--;
  std::cout << this->_ScavPrefix << "attacks " << target << ", causing "
            << this->_dmg << " points of damage! Energy: " << this->_energy
            << std::endl;
}

void ScavTrap::guardGate()
{
  std::cout << this->_ScavPrefix << "is now in Gatekeeper mode!" << std::endl;
}
