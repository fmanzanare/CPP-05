/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:44:15 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 12:40:13 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat b1("Antonio", 149);

	std::cout << b1;
	try {
		b1.decrementGrade();
	} catch (...) {
		std::cout << "Bureaucrat b1 grade too low." << std::endl;
	}
	std::cout << b1;

	try {
		Bureaucrat b2("Pepe", 151);
	} catch (...) {
		std::cout << "Bureaucrat b2 grade too high." << std::endl;
	}

	return (0);
}
