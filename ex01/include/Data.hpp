/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:31:19 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/09 05:31:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
private:
	std::string _name;
	int _age;
	double _value;

public:
	Data(void);
	Data(const std::string& name, int age, double value);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data(void);

	std::string getName(void) const;
	int getAge(void) const;
	double getValue(void) const;
};

#endif
