/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:34:49 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 13:41:49 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	Form f1("f1", 5, 5);
	Form f2("f2", 149, 149);

	Bureaucrat b1("Paco", 1);
	Bureaucrat b2("Antonio", 150);

	try {
		f1.beSigned(b1);
		b1.signForm(f1);
	} catch(...) {
		std::cout << "The form -f1- was not signed!" << std::endl;
	}

	try {
		f2.beSigned(b2);
		b2.signForm(f2);
	} catch(...) {
		std::cout << "The form -f2- was not signed!" << std::endl;
	}

	return (0);
}
