/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/21 11:01:15 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
  private:
    ClapTrap();

    std::string _name;
    std::string _prefix;
    long        _hp;
    long        _energy;
    int         _dmg;

  public:
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void beRepaired(unsigned int amount);
    void takeDamage(unsigned int amount);
    void attack(const std::string& target);
};

#endif
