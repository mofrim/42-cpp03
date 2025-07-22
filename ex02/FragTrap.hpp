/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:52:19 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/22 16:50:55 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
  private:
    FragTrap();

  public:
    // OCF
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    virtual void beRepaired(unsigned int amount);
    virtual void takeDamage(unsigned int amount);
    virtual void attack(const std::string& target);

    void highFivesGuys();
};

#endif
