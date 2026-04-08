/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:36:24 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/09 05:28:43 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
public:
	static void convert(const std::string& str);
};

#endif
