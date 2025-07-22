/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/22 21:39:52 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
  private:
    std::string _prefix;

    // INSIGHT: needed to make this a function !! because with making the prefix
    // a variable would demand updating (and not forgetting about this!) with
    // every assignment or whatnot.
    const std::string _getPrefix();

  protected:
    ClapTrap();

    std::string _name;
    long        _hp;
    long        _energy;
    int         _dmg;

  public:
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    virtual void beRepaired(unsigned int amount);
    virtual void takeDamage(unsigned int amount);
    virtual void attack(const std::string& target);
};

#endif
