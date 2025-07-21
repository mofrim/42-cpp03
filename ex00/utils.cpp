/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:37:16 by fmaurer           #+#    #+#             */
/*   Updated: 2025/07/21 10:32:06 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#include <iostream>

void dbg_msg(const std::string& name, const std::string& msg)
{
  if (DEBUG)
    std::cout << "[" << name << "] " << msg << std::endl;
}
