/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:38:58 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 21:30:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// well the virtual public... solves the diamond problem. this is exactly what
// we have here: one base class is inherited through mutiple paths. without it
// the compiler would not know if it should take the members from ClapTrap
// inherited by ScavTrap or from ClapTrap inherited by FragTrap.
//
// Also needed to make the _dmg variable explicit member of ScavTrap in order to
// save the custom dmg value from FragTrap.
class ScavTrap: virtual public ClapTrap
{
  private:
    std::string _msgPrefix;
    std::string _name;
    void        printStats() const;

  protected:
    ScavTrap();
    int _dmg;

  public:
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void attack(const std::string& target);

    void guardGate();
};

#endif
