/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:38 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 18:31:33 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestFrom.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45), _target("none") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp) : AForm(cp) {
	*this = cp;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cp) {
	this->_target = cp._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	AForm::execute(executor);
	std::cout << "rrriiii wrii bip bip" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " robotomy process was succesfull" << std::endl;
	else
		std::cout << this->_target << " robotomy failed" << std::endl;
}
