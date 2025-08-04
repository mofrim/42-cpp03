/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:52:15 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 20:52:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "utils.hpp"

#include <iomanip>
#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
  this->_name      = "noname";
  this->_hp        = 100;
  this->_nrg       = 100;
  this->_dmg       = 30;
  this->_msgPrefix = get_prefix("FragTrap", this->_name);
  dbg_msg("FragTrap " + this->_name, "Default constructor called.");
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
  this->_name      = name;
  this->_hp        = 100;
  this->_nrg       = 100;
  this->_dmg       = 30;
  this->_msgPrefix = get_prefix("FragTrap", this->_name);
  dbg_msg("FragTrap " + this->_name, "Default-Name Constructor called.");
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
  dbg_msg("FragTrap " + this->_name, "Copy-Constructor called.");
  this->_name      = other._name;
  this->_msgPrefix = other._msgPrefix;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  dbg_msg("FragTrap " + this->_name, "Assignment-Constructor called.");
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

FragTrap::~FragTrap()
{
  dbg_msg("FragTrap " + this->_name, "Destructor called.");
};

void FragTrap::highFivesGuys() const
{
  std::cout << this->_msgPrefix << "come on high-fives ?!" << std::endl;
}

void FragTrap::printStats() const
{
  std::cout << std::setw(this->_msgPrefix.length()) << " ";
  std::cout << ">>> " << this->_name << "'s stats: {nrg: " << this->_nrg
            << ", hp: " << this->_hp << ", dmg: " << this->_dmg << "}"
            << std::endl;
}
