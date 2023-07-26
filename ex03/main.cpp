/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:40:10 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/26 16:49:33 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestFrom.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat b1("Pepe", 5);
	Bureaucrat b2("Manolo", 140);
	Bureaucrat b3("Antonio", 100);
	Bureaucrat b4("Paco", 150);

	AForm *form;
	Intern i = Intern();

	form = i.makeForm("shrubbery creation form", "file");
	if (form == NULL)
		return (1);

	try {
		form->beSigned(b4);
	} catch (std::exception &e) {
		std::cout << "shrubbery could not be signed because " << e.what() << std::endl;
	}

	try {
		b4.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "shrubbery could not be executed because " << e.what() << std::endl;
	}
	delete form;

	form = i.makeForm("robotomy request form", "Paco");
	if (form == NULL)
		return (1);
	try {
		form->beSigned(b1);
	} catch (std::exception &e) {
		std::cout << "robotomy could not be signed because " << e.what() << std::endl;
	}

	try {
		b1.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "robotomy could not be executed because " << e.what() << std::endl;
	}
	delete form;

	form = i.makeForm("presidetial pardon form", "Paco");
	if (form == NULL)
		return (1);
	try {
		form->beSigned(b1);
	} catch (std::exception &e) {
		std::cout << "presidential could not be signed because " << e.what() << std::endl;
	}

	try {
		b1.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "presidential could not be executed because " << e.what() << std::endl;
	}
	delete form;

	return (0);
}
