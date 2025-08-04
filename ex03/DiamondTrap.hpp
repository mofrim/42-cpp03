/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:57:39 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 07:09:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

// inherits both not-so-base classes. Default constructor, _name, _msgPrefix and
// printStats shall be private because we want a Diamond trap to know its
// individuality.
class DiamondTrap: public ScavTrap, public FragTrap
{
  private:
    DiamondTrap();
    std::string _name;
    std::string _msgPrefix;
    void        printStats() const;

  public:
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void whoAmI();
};

#endif
