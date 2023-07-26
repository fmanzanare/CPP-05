/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:13:21 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/26 16:50:08 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestFrom.hpp"
#include "PresidentialPardonForm.hpp"

std::string stringToLower(std::string str)
{
	for(std::size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	return (str);
}

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &cp) {
	*this = cp;
}

Intern &Intern::operator=(const Intern &cp) {
	(void)cp;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	AForm *form = NULL;
	formName = stringToLower(formName);

	std::string opts[] = {
		"shrubbery",
		"robotomy",
		"presidential"
	};

	int i = 0;

	for (i = 0; i < 3; i++) {
		if (formName.find(opts[i]) != std::string::npos) {
			break ;
		}
	}

	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates Shrubbery form" << std::endl;
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates Robotomy form" << std::endl;
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates Presidential form" << std::endl;
			break;
		default:
			std::cout << "Intern could not create form because it does not exist" << std::endl;
			break;
	}

	return (form);
}
