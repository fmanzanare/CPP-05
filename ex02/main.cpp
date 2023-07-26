/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:40:10 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/26 13:56:25 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestFrom.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat b1("Pepe", 5);
	Bureaucrat b2("Manolo", 140);
	Bureaucrat b3("Antonio", 100);
	Bureaucrat b4("Paco", 150);

	ShrubberyCreationForm s1("trees");
	RobotomyRequestForm r1("Manolo");
	PresidentialPardonForm p1("Paco");

	try {
		s1.beSigned(b4);
	} catch (std::exception &e) {
		std::cout << "s1 could not be signed because " << e.what() << std::endl;
	}

	try {
		b4.executeForm(s1);
	} catch (std::exception &e) {
		std::cout << "s1 could not be executed because " << e.what() << std::endl;
	}

	try {
		r1.beSigned(b1);
	} catch (std::exception &e) {
		std::cout << "r1 could not be signed because " << e.what() << std::endl;
	}

	try {
		b4.executeForm(r1);
	} catch (std::exception &e) {
		std::cout << "r1 could not be executed because " << e.what() << std::endl;
	}

	try {
		p1.beSigned(b1);
	} catch (std::exception &e) {
		std::cout << "p1 could not be signed because " << e.what() << std::endl;
	}

	try {
		b1.executeForm(p1);
	} catch (std::exception &e) {
		std::cout << "p1 could not be executed because " << e.what() << std::endl;
	}

	return (0);
}
