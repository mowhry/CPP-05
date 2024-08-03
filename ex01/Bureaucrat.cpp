#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default Bureaucrat"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	//destructor called
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &os)
{
	if (this != &os)
		this->_grade = os._grade;
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::gradeMinus()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
	std::cout << "\033[31m" << "DEFEAT" << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "-10,000 aura and you're getting demoted to a lower rank bozo" << "\033[0m" << std::endl;
}

void Bureaucrat::gradePlus()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
	std::cout << "\033[32m" << "VICTORY" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "+10,000 aura and you're getting promoted to a higher rank King" << "\033[0m" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}