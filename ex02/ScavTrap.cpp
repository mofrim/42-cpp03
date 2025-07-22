/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:48:30 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/21 11:07:22 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "utils.hpp"

#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
  dbg_msg("ScavTrap", "Default constructor called.");
  _hp     = 100;
  _energy = 50;
  _dmg    = 20;
  _prefix = "_ScavTrap_ (" + _name + ") ";
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
  dbg_msg("ScavTrap", "Default-Name constructor called.");
  _hp     = 100;
  _energy = 50;
  _dmg    = 20;
  _prefix = "_ScavTrap_ (" + _name + ") ";
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
  dbg_msg("ScavTrap", "copy constructor called.");
  _prefix = "_ScavTrap_ (" + _name + ") ";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  dbg_msg("ScavTrap", "assignment constructor called.");
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
    _prefix = "_ScavTrap_ (" + _name + ") ";
  }
  return (*this);
}

ScavTrap::~ScavTrap() { dbg_msg("ScavTrap", "Destructor called."); };

void ScavTrap::beRepaired(unsigned int amount)
{
  if (_hp == -1)
  {
    std::cout << _prefix << "already dead!" << std::endl;
    return;
  }
  if (_energy == 0)
  {
    std::cout << _prefix << "has 0 energy. No more repair possible!"
              << std::endl;
    return;
  }
  _hp += amount;
  _energy--;
  std::cout << _prefix << "is being repaired by " << amount
            << " hitpoints. Remaining HP: " << _hp
            << ", remaining energy: " << _energy << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
  if (_hp == -1)
  {
    std::cout << _prefix << "already dead!" << std::endl;
    return;
  }
  if (_hp > amount)
  {
    _hp -= amount;
    std::cout << _prefix << "takes " << amount
              << " hitpoints of damage. Remaining HP: " << _hp << std::endl;
  } else if (_hp == amount)
  {
    std::cout
        << _prefix << "takes " << amount
        << " hitpoints of damage. Remaining HP: 0. One more strike till death! "
        << std::endl;
    _hp = 0;

  } else
  {
    std::cout << _prefix << " takes " << amount
              << " hitpoints of damage. HP < 0 -> Dead! " << std::endl;
    _hp = -1;
  }
}

void ScavTrap::attack(const std::string& target)
{
  if (_hp == -1)
  {
    std::cout << _prefix << "already dead!" << std::endl;
    return;
  }
  if (_energy == 0)
  {
    std::cout << _prefix << "has 0 energy. No more attacks possible!"
              << std::endl;
    return;
  }
  _energy--;
  std::cout << _prefix << "attacks " << target << ", causing " << _dmg
            << " points of damage! Energy: " << _energy << std::endl;
}

void ScavTrap::guardGate()
{
  std::cout << _prefix << "is now in Gatekeeper mode!" << std::endl;
}
