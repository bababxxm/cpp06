/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:32:48 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/26 23:19:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _name("Unknown"), _age(0), _value(0.0) {}

Data::Data(const std::string &name, int age, double value)
    : _name(name), _age(age), _value(value) {}

Data::Data(const Data &other)
    : _name(other._name), _age(other._age), _value(other._value) {}

Data &Data::operator=(const Data &other) {
  if (this != &other) {
    _name = other._name;
    _age = other._age;
    _value = other._value;
  }
  return (*this);
}

Data::~Data(void) {}

std::string Data::getName(void) const { return (_name); }
int Data::getAge(void) const { return (_age); }
double Data::getValue(void) const { return (_value); }
