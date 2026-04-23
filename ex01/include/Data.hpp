/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:31:19 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/23 10:47:00 by sklaokli         ###   ########.fr       */
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
	Data();
	Data(const std::string&, int, double);
	Data(const Data&);
	Data& operator=(const Data&);
	~Data();

	std::string getName() const;
	int getAge() const;
	double getValue() const;
};

#endif
