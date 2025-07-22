/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:48:30 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/22 20:22:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "utils.hpp"

#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
  _name   = "Elon";
  _hp     = 100;
  _energy = 50;
  _dmg    = 20;
  _prefix = "_ScavTrap_ (" + _name + ") ";
  dbg_msg("ScavTrap " + _name, "Default constructor called.");
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{

  _name   = name;
  _hp     = 100;
  _energy = 50;
  _dmg    = 20;
  _prefix = "_ScavTrap_ (" + _name + ") ";
  dbg_msg("ScavTrap " + _name, "Default-Name constructor called.");
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
  _prefix = "_ScavTrap_ (" + _name + ") ";
  dbg_msg("ScavTrap " + _name, "copy constructor called.");
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
    _prefix = "_ScavTrap_ (" + _name + ") ";
  }
  dbg_msg("ScavTrap " + _name, "assignment constructor called.");
  return (*this);
}

ScavTrap::~ScavTrap() { dbg_msg("ScavTrap " + _name, "Destructor called."); };

void ScavTrap::attack(const std::string& target)
{
  if (_hp == -1)
  {
    std::cout << "_ScavTrap_ (" + _name + ") " << "already dead!" << std::endl;
    return;
  }
  if (_energy == 0)
  {
    std::cout << "_ScavTrap_ (" + _name + ") "
              << "has 0 energy. No more attacks possible!" << std::endl;
    return;
  }
  _energy--;
  std::cout << "_ScavTrap_ (" + _name + ") " << "attacks " << target
            << ", causing " << _dmg << " points of damage! Energy: " << _energy
            << std::endl;
}

void ScavTrap::guardGate()
{
  std::cout << "_ScavTrap_ (" + _name + ") " << "is now in Gatekeeper mode!"
            << std::endl;
}
