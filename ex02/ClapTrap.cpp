/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:44:36 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 21:58:59 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"

#include <iomanip>
#include <iostream>

ClapTrap::ClapTrap(): _name("noname"), _hp(10), _nrg(10), _dmg(0)
{
  dbg_msg("ClapTrap " + this->_name, "Default Constructor called.");
  this->_msgPrefix = get_prefix("ClapTrap", this->_name);
}

ClapTrap::ClapTrap(const std::string& name):
  _name(name), _hp(10), _nrg(10), _dmg(0)
{
  dbg_msg("ClapTrap " + this->_name, "Default-Name Constructor called.");
  this->_msgPrefix = get_prefix("ClapTrap", this->_name);
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
  dbg_msg("ClapTrap " + this->_name, "Copy-Constructor called.");
  if (this != &other)
  {
    this->_name      = other._name;
    this->_hp        = other._hp;
    this->_nrg       = other._nrg;
    this->_dmg       = other._dmg;
    this->_msgPrefix = other._msgPrefix;
  }
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
  dbg_msg("ClapTrap " + this->_name, "Assignment-Constructor called.");
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

ClapTrap::~ClapTrap()
{
  dbg_msg("ClapTrap " + this->_name, "Destructor called.");
}

void ClapTrap::beRepaired(const unsigned int& amount)
{
  if (this->_hp == -1)
  {
    std::cout << this->_msgPrefix << "trying to be repaired but already dead!"
              << std::endl;
    printStats();
    return;
  }
  if (this->_nrg == 0)
  {
    std::cout << this->_msgPrefix << "has 0 energy. No more repair possible!"
              << std::endl;
    printStats();
    return;
  }
  this->_hp += amount;
  this->_nrg--;
  std::cout << this->_msgPrefix << "is being repaired by " << amount << " hp."
            << std::endl;
  printStats();
}

void ClapTrap::takeDamage(const unsigned int& amount)
{
  if (this->_hp == -1)
  {
    std::cout << this->_msgPrefix << "takes " << amount
              << " hp damage, was already dead before, now is even deader!"
              << std::endl;
    printStats();
    return;
  }
  if (_hp > amount)
  {
    this->_hp -= amount;
    std::cout << this->_msgPrefix << "takes " << amount << " hp of damage."
              << std::endl;
    printStats();
  } else if (this->_hp == amount)
  {
    std::cout << this->_msgPrefix << "takes " << amount
              << " hp of damage. HP == 0, One more strike till death! "
              << std::endl;
    this->_hp = 0;
    printStats();
  } else
  {
    std::cout << this->_msgPrefix << "takes " << amount
              << " hp of damage. HP < 0 -> Dead! " << std::endl;
    this->_hp = -1;
    printStats();
  }
}

void ClapTrap::attack(const std::string& target)
{
  if (this->_hp == -1)
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
            << this->_dmg << " hp of damage!" << std::endl;
  printStats();
}

void ClapTrap::printStats() const
{
  std::cout << std::setw(this->_msgPrefix.length()) << " ";
  std::cout << ">>> " << this->_name << "'s stats: {nrg: " << this->_nrg
            << ", hp: " << this->_hp << ", dmg: " << this->_dmg << "}"
            << std::endl;
}
