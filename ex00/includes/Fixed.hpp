/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:18:53 by pineau            #+#    #+#             */
/*   Updated: 2024/01/22 15:17:29 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed&);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
	private:
		int	_fixed_nbr;
		static const int _bits;	
};

#endif