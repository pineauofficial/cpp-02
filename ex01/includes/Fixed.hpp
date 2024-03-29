/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:39 by pineau            #+#    #+#             */
/*   Updated: 2024/01/23 15:03:50 by pineau           ###   ########.fr       */
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
		
	private:
		int	_fixed_nbr;
		static const int _bits;	
};

std::ostream & operator<<(std::ostream & ost, Fixed const & rhs);

#endif