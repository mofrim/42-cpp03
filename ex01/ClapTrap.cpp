/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:44:36 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/21 11:01:03 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"

#include <iostream>

ClapTrap::ClapTrap(): _name("Elon"), _hp(10), _energy(10), _dmg(0)
{
  dbg_msg("ClapTrap", "Default Constructor called.");
  _prefix = "_ClapTrap_ (" + _name + ") ";
}

ClapTrap::ClapTrap(const std::string& name):
  _name(name), _hp(10), _energy(10), _dmg(0)
{
  dbg_msg("ClapTrap", "Default-Name Constructor called.");
  _prefix = "_ClapTrap_ (" + _name + ") ";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
  dbg_msg("ClapTrap", "Copy-Constructor called.");
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
    _prefix = "_ClapTrap_ (" + _name + ") ";
  }
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
  dbg_msg("ClapTrap", "Assignment-Constructor called.");
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
    _prefix = "_ClapTrap_ (" + _name + ") ";
  }
  return (*this);
}

ClapTrap::~ClapTrap() { dbg_msg("ClapTrap", "Destructor called."); }

void ClapTrap::beRepaired(unsigned int amount)
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

void ClapTrap::takeDamage(unsigned int amount)
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

void ClapTrap::attack(const std::string& target)
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
