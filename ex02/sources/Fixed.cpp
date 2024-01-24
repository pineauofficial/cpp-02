/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:12:29 by pineau            #+#    #+#             */
/*   Updated: 2024/01/24 13:35:23 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

/***************/
/*constructeurs*/
/***************/

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

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_nbr = nbr << this->_bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_nbr = (int)roundf(nbr * (1 << this->_bits));
}

/**************************/
/*operateurs d'affectation*/
/**************************/

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_fixed_nbr = src.getRawBits();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & ost, Fixed const &rhs)
{
	ost << rhs.toFloat();
	return ost;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixed_nbr > rhs._fixed_nbr);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixed_nbr < rhs._fixed_nbr);
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	return (this->_fixed_nbr >= rhs._fixed_nbr);
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	return (this->_fixed_nbr <= rhs._fixed_nbr);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	return (this->_fixed_nbr == rhs._fixed_nbr);
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	return (this->_fixed_nbr != rhs._fixed_nbr);
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed	tmp;
	tmp.setRawBits(this->_fixed_nbr + rhs._fixed_nbr);
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed	tmp;
	tmp.setRawBits(this->_fixed_nbr - rhs._fixed_nbr);
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed	tmp;
	tmp.setRawBits((this->_fixed_nbr * rhs._fixed_nbr) >> this->_bits);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed	tmp;
	tmp.setRawBits((this->_fixed_nbr << this->_bits) / rhs._fixed_nbr);
	return (tmp);
}

//post fix
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_fixed_nbr++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_fixed_nbr--;
	return (tmp);
}

//pre fix
Fixed	&Fixed::operator++(void)
{
	this->_fixed_nbr++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixed_nbr--;
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
	return ((float)this->_fixed_nbr / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return this->_fixed_nbr >> this->_bits;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
