/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:29 by pineau            #+#    #+#             */
/*   Updated: 2024/01/22 17:41:40 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

/******************************************/
/*constructeurs et operateur d'affectation*/
/******************************************/

Fixed::Fixed(void) : _fixed_nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	//truc a faire	
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	//truc a faire 
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_fixed_nbr = src.getRawBits();
	}
	return (*this);
}

/*****************/
/*setter & getter*/
/*****************/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this-> _fixed_nbr);
}

void Fixed::setRawBits(int const raw)
{
	this-> _fixed_nbr = raw;
}

/*******************/
/*fonctions membres*/
/*******************/

float Fixed::toFloat(void) const
{
	//truc a faire
}

int Fixed::toInt(void) const
{
	//truc a faire
}

Fixed &Fixed::operator<<(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
}
