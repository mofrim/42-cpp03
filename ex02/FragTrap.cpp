/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:52:15 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/22 16:53:14 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "utils.hpp"

#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
  dbg_msg("FragTrap", "Default constructor called.");
  _hp     = 100;
  _energy = 100;
  _dmg    = 30;
  _prefix = "_FragTrap_ (" + _name + ") ";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
  dbg_msg("FragTrap", "Default-Name constructor called.");
  _hp     = 100;
  _energy = 100;
  _dmg    = 30;
  _prefix = "_FragTrap_ (" + _name + ") ";
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
  dbg_msg("FragTrap", "copy constructor called.");
  _prefix = "_FragTrap_ (" + _name + ") ";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  dbg_msg("FragTrap", "assignment constructor called.");
  if (this != &other)
  {
    _name   = other._name;
    _hp     = other._hp;
    _energy = other._energy;
    _dmg    = other._dmg;
    _prefix = "_FragTrap_ (" + _name + ") ";
  }
  return (*this);
}

FragTrap::~FragTrap() { dbg_msg("FragTrap", "Destructor called."); };

void FragTrap::beRepaired(unsigned int amount)
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

void FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::attack(const std::string& target)
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

void FragTrap::highFivesGuys()
{
  std::cout << _prefix << "common high-fives ?!" << std::endl;
}
