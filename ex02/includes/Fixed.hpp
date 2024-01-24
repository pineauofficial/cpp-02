/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:27:11 by pineau            #+#    #+#             */
/*   Updated: 2024/01/24 13:35:45 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed&);
		Fixed(const int nbr);
		Fixed(const float nbr);
		
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
		
		bool operator>(const Fixed & rhs)const ;
		bool operator<(const Fixed & rhs)const ;
		bool operator>=(const Fixed & rhs);
		bool operator<=(const Fixed & rhs);
		bool operator==(const Fixed & rhs);
		bool operator!=(const Fixed & rhs);
		Fixed operator+(const Fixed & rhs);
		Fixed operator-(const Fixed & rhs);
		Fixed operator*(const Fixed & rhs);
		Fixed operator/(const Fixed & rhs);
		Fixed & operator++(void);
		Fixed operator++(int);
		Fixed & operator--(void);
		Fixed operator--(int);
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);
		
		
	private:
		int	_fixed_nbr;
		static const int _bits;	
};

std::ostream & operator<<(std::ostream & ost, Fixed const & rhs);

#endif