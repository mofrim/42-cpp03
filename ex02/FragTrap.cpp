/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:52:15 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/24 20:35:25 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "utils.hpp"

#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
  dbg_msg("FragTrap " + this->_name, "Default constructor called.");
  this->_hp         = 100;
  this->_energy     = 100;
  this->_dmg        = 30;
  this->_FragPrefix = "_FragTrap_ (" + this->_name + ") ";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
  dbg_msg("FragTrap " + this->_name, "Default-Name constructor called.");
  this->_hp         = 100;
  this->_energy     = 100;
  this->_dmg        = 30;
  this->_FragPrefix = "_FragTrap_ (" + this->_name + ") ";
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
  dbg_msg("FragTrap " + this->_name, "Copy-Constructor called.");
  this->_FragPrefix = other._FragPrefix;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  dbg_msg("FragTrap " + this->_name, "Assignment-Constructor called.");
  if (this != &other)
  {
    this->_name       = other._name;
    this->_hp         = other._hp;
    this->_energy     = other._energy;
    this->_dmg        = other._dmg;
    this->_FragPrefix = other._FragPrefix;
  }
  return (*this);
}

FragTrap::~FragTrap()
{
  dbg_msg("FragTrap " + this->_name, "Destructor called.");
};

void FragTrap::highFivesGuys()
{
  std::cout << this->_FragPrefix << "come on high-fives ?!" << std::endl;
}
