/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:52:15 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/24 20:21:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "utils.hpp"

#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
  dbg_msg("FragTrap " + _name, "Default constructor called.");
  _hp     = 100;
  _energy = 100;
  _dmg    = 30;
  _name = "noname";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
  _hp     = 100;
  _energy = 100;
  _dmg    = 30;
  _name = name;
  dbg_msg("FragTrap " + _name, "Default-Name constructor called.");
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
  dbg_msg("FragTrap " + _name, "copy constructor called.");
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  if (this != &other)
  {
    _name   = other._name;
    std::cout << "other name: " << other._name << std::endl;
    ClapTrap::_name = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
  }
  dbg_msg("FragTrap " + _name, "assignment constructor called.");
  return (*this);
}

FragTrap::~FragTrap() { dbg_msg("FragTrap " + _name, "Destructor called."); };

void FragTrap::highFivesGuys()
{
  std::cout << "_FragTrap_ (" + _name + ") " << "come on, high-fives ?!" << std::endl;
}
