/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:26:19 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 18:21:14 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery", 145, 137), _target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp) : AForm(cp) {
	*this = cp;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cp) {
	this->_target = cp._target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::ofstream outfile;

	AForm::execute(executor);
	outfile.open((this->_target + "_shrubbery").c_str());
	if (!outfile) {
		std::cout << this->_target + "_shrubbery" << " file could not be openned!" << std::endl;
		exit (1);
	}

	outfile <<
	" _                 \n" <<
	"| |                \n" <<
	"| |_ _ __ ___  ___ \n" <<
	"| __| '__/ _ \\/ _ \\\n" <<
	"| |_| | |  __/  __/\n" <<
	"\\__|_|  \\___|\\___|\n"
	<< "\n\n\n" <<
	"      _-_\n" <<
	"    /~~   ~~\\\n" <<
	" /~~         ~~\\\n" <<
	"{               }\n" <<
	" \\  _-     -_  /\n" <<
	"   ~  \\\\ //  ~\n" <<
	"_- -   | | _- _\n" <<
	"  _ -  | |   -_\n" <<
	"      // \\\\\n" << std::endl;

	outfile.close();
}











