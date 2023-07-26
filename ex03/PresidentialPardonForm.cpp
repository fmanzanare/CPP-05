/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:35:58 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/26 13:48:19 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("presidential", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cp) : AForm(cp) {
	*this = cp;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cp) {
	this->_target = cp._target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
