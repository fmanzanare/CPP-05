/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:27:29 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/07 17:47:45 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Noname"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	if (grade < 1) {
		throw std::out_of_range("GradeTooHighException: The maximum grade is 1.");
	} else if (grade > 150) {
		throw std::out_of_range("GradeTooLowException: The minimum grade is 150.");
	} else {
		this->_grade = grade;
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &cp) {
	*this = cp;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cp) {
	// this->_name cannot be modified, due to it is a constant.
	this->_grade = cp._grade;
	return (*this);
}

std::string const Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1) {
		throw std::out_of_range("GradeTooHighException: The Bureaucrat already has the maximum grade.");
	} else {
		this->_grade--; // 1 is higher than 150. Both are the limits.
	}
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150) {
		throw std::out_of_range("GradeTooLowException: The Bureaucrat already has the minimum grade.");
	} else {
		this->_grade++; // 1 is higher than 150. Both are the limits.
	}
}
