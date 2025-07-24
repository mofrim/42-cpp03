/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:44:36 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/24 20:25:02 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"

#include <iostream>

ClapTrap::ClapTrap(): _name("noname"), _hp(10), _energy(10), _dmg(0)
{
  dbg_msg("ClapTrap " + this->_name, "Default Constructor called.");
  this->_ClapPrefix = "_ClapTrap_ (" + this->_name + ") ";
}

ClapTrap::ClapTrap(const std::string& name):
  _name(name), _hp(10), _energy(10), _dmg(0)
{
  dbg_msg("ClapTrap " + this->_name, "Default-Name Constructor called.");
  this->_ClapPrefix = "_ClapTrap_ (" + this->_name + ") ";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
  dbg_msg("ClapTrap " + this->_name, "Copy-Constructor called.");
  if (this != &other)
  {
    this->_name       = other._name;
    this->_hp         = other._hp;
    this->_energy     = other._energy;
    this->_dmg        = other._dmg;
    this->_ClapPrefix = other._ClapPrefix;
  }
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
  dbg_msg("ClapTrap " + this->_name, "Assignment-Constructor called.");
  if (this != &other)
  {
    this->_name       = other._name;
    this->_hp         = other._hp;
    this->_energy     = other._energy;
    this->_dmg        = other._dmg;
    this->_ClapPrefix = other._ClapPrefix;
  }
  return (*this);
}

ClapTrap::~ClapTrap()
{
  dbg_msg("ClapTrap " + this->_name, "Destructor called.");
}

void ClapTrap::beRepaired(const unsigned int& amount)
{
  if (this->_hp == -1)
  {
    std::cout << this->_ClapPrefix << "already dead!" << std::endl;
    return;
  }
  if (this->_energy == 0)
  {
    std::cout << this->_ClapPrefix << "has 0 energy. No more repair possible!"
              << std::endl;
    return;
  }
  this->_hp += amount;
  this->_energy--;
  std::cout << this->_ClapPrefix << "is being repaired by " << amount
            << " hitpoints. Remaining HP: " << this->_hp
            << ", remaining energy: " << this->_energy << std::endl;
}

void ClapTrap::takeDamage(const unsigned int& amount)
{
  if (this->_hp == -1)
  {
    std::cout << this->_ClapPrefix << "already dead!" << std::endl;
    return;
  }
  if (_hp > amount)
  {
    this->_hp -= amount;
    std::cout << this->_ClapPrefix << "takes " << amount
              << " hitpoints of damage. Remaining HP: " << this->_hp
              << std::endl;
  } else if (this->_hp == amount)
  {
    std::cout
        << this->_ClapPrefix << "takes " << amount
        << " hitpoints of damage. Remaining HP: 0. One more strike till death! "
        << std::endl;
    this->_hp = 0;
  } else
  {
    std::cout << this->_ClapPrefix << " takes " << amount
              << " hitpoints of damage. HP < 0 -> Dead! " << std::endl;
    this->_hp = -1;
  }
}

void ClapTrap::attack(const std::string& target)
{
  if (this->_hp == -1)
  {
    std::cout << this->_ClapPrefix << "already dead!" << std::endl;
    return;
  }
  if (this->_energy == 0)
  {
    std::cout << this->_ClapPrefix << "has 0 energy. No more attacks possible!"
              << std::endl;
    return;
  }
  this->_energy--;
  std::cout << this->_ClapPrefix << "attacks " << target << ", causing "
            << this->_dmg << " points of damage! Energy: " << this->_energy
            << std::endl;
}
