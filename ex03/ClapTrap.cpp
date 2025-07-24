/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:44:36 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/24 20:21:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"

#include <iostream>

ClapTrap::ClapTrap(): _name("noname"), _hp(10), _energy(10), _dmg(0)
{
  dbg_msg("ClapTrap " + _name, "Default Constructor called.");
}

ClapTrap::ClapTrap(const std::string& name):
  _name(name), _hp(10), _energy(10), _dmg(0)
{
  dbg_msg("ClapTrap " + _name, "Default-Name Constructor called.");
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
  }
  dbg_msg("ClapTrap " + _name, "Copy-Constructor called.");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
  }
  dbg_msg("ClapTrap " + _name, "Assignment-Constructor called.");
  return (*this);
}

ClapTrap::~ClapTrap() { dbg_msg("ClapTrap " + _name, "Destructor called."); }

const std::string ClapTrap::_getPrefix()
{
  std::string prefix("_ClapTrap_ (" + _name + ") ");
  return (prefix);
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (_hp == -1)
  {
    std::cout << _getPrefix() << "already dead!" << std::endl;
    return;
  }
  if (_energy == 0)
  {
    std::cout << _getPrefix() << "has 0 energy. No more repair possible!"
              << std::endl;
    return;
  }
  _hp += amount;
  _energy--;
  std::cout << _getPrefix() << "is being repaired by " << amount
            << " hitpoints. Remaining HP: " << _hp
            << ", remaining energy: " << _energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (_hp == -1)
  {
    std::cout << _getPrefix() << "already dead!" << std::endl;
    return;
  }
  if (_hp > amount)
  {
    _hp -= amount;
    std::cout << _getPrefix() << "takes " << amount
              << " hitpoints of damage. Remaining HP: " << _hp << std::endl;
  } else if (_hp == amount)
  {
    std::cout
        << _getPrefix() << "takes " << amount
        << " hitpoints of damage. Remaining HP: 0. One more strike till death! "
        << std::endl;
    _hp = 0;

  } else
  {
    std::cout << _getPrefix() << " takes " << amount
              << " hitpoints of damage. HP < 0 -> Dead! " << std::endl;
    _hp = -1;
  }
}

void ClapTrap::attack(const std::string& target)
{
  if (_hp == -1)
  {
    std::cout << _getPrefix() << "already dead!" << std::endl;
    return;
  }
  if (_energy == 0)
  {
    std::cout << _getPrefix() << "has 0 energy. No more attacks possible!"
              << std::endl;
    return;
  }
  _energy--;
  std::cout << _getPrefix() << "attacks " << target << ", causing " << _dmg
            << " points of damage! Energy: " << _energy << std::endl;
}
