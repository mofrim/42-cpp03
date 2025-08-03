/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 19:26:42 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

// had to make some members protected, not private. otherwise ScavTrap wouldn't
// be able to access theses members. except for the _ClapPrefix which should not
// be re-used in derived classes.
class ClapTrap
{
  private:
    std::string _msgPrefix;

  protected:
    ClapTrap();

    std::string _name;
    long        _hp;
    long        _nrg;
    int         _dmg;

  public:
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void beRepaired(const unsigned int& amount);
    void takeDamage(const unsigned int& amount);
    void attack(const std::string& target);

    void printStats() const;
};

#endif
