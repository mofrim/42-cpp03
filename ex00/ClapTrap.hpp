/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:42:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 18:31:44 by fmaurer          ###   ########.fr       */
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
    std::string _msgPrefix;
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
