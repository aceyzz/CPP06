/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:33:18 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/03 22:33:18 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// COPLIEN'S FORM
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string &input)
{
	if (isChar(input))
		toChar(input);
	else if (isInt(input))
		toInt(input);
	else if (isFloat(input))
		toFloat(input);
	else if (isDouble(input))
		toDouble(input);
	else if (isOther(input))
		toOther(input);
	else
		std::cout << YLLW "Invalid input. Enter a char, int, float or double value." RST << std::endl;
}

// CHAR //////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isChar(const std::string &input)
{
	if (input.size() == 1)
		return (true);
	if (input.size() == 3)
		if (input[0] == '\'' && input[2] == '\'')
			return (true);
	return (false);
}

void	ScalarConverter::toChar(const std::string &input)
{
	char	c = input[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (input.size() == 3)
		if (input[0] == '\'' && input[2] == '\'')
			c = input[1];

	if (isprint(c))
		std::cout << GOLD "char:   \t'" << c << "'" RST << std::endl;
	else
		std::cout << RED1 "char:   \t" << "non displayable" RST << std::endl;
	std::cout << LIME "int:    \t" << i << RST << std::endl;
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f  << "f" RST << std::endl;
	std::cout << ORNG "double: \t" << d << RST << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////

// INT ////////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isInt(const std::string &input)
{
	size_t	startIndex = 0;

	if (input.empty()) return (false);

	while (startIndex < input.size() && std::isspace(input[startIndex]))
		startIndex++;
	if (startIndex == input.size())
		return (false);
	if (input[startIndex] == '+' || input[startIndex] == '-')
		startIndex++;
	if (startIndex == input.size() || !std::isdigit(input[startIndex]))
		return (false);
	for (size_t i = startIndex; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}

	try
	{
		long long int result = std::stoll(input);
		if (result < INT_MIN || result > INT_MAX)
			return (false);
	}
	catch (const std::invalid_argument &e) { return (false); }//	Oui j'ai des tendances paranos++
	catch (const std::out_of_range &e) { return (false); }// 		Oui j'ai des tendances paranos++

	return (true);
}

void	ScalarConverter::toInt(const std::string &input)
{
	char	c;
	int		i = std::stoi(input);
	float	f;
	double	d;


	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RST << std::endl;
		else
			std::cout << RED1 "char:   \t" << "non displayable" RST << std::endl;
	}
	else
		std::cout << REDD "char:   \t" << "impossible" RST << std::endl;
	std::cout << LIME "int:    \t" << i << RST << std::endl;
	
	f = static_cast<float>(i);
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f << "f" RST << std::endl;
	d = static_cast<double>(i);
	std::cout << ORNG "double: \t" << d << RST << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////



// FLOAT //////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty()) return (false);


	bool	digitBeforeDecimal = false;
	bool	decimalFound = false;
	bool	digitAfterDecimal = false;
	size_t	i = 0;

	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i == input.size())
		return (false);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);

	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitBeforeDecimal = true;

	if (i < input.size() && input[i] == '.')
	{
		decimalFound = true;
		i++;
	}
	// Vérifie les chiffres après le point
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitAfterDecimal = true;
	// Finir par 'f' ou 'F' après les chiffres
	if (i == input.size() - 1 && (input[i] == 'f' || input[i] == 'F')
		&& (digitBeforeDecimal || digitAfterDecimal) && decimalFound)
		return (true);

	return (false);
}

void	ScalarConverter::toFloat(const std::string &input)
{
	char	c;
	int		i;
	float	f = stof(input);
	double	d;

	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(f);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RST << std::endl;
		else
			std::cout << RED1 "char:   \t" << "non displayable" RST << std::endl;
	}
	else
		std::cout << REDD "char:   \t" << "impossible" RST << std::endl;
	
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(f);
		std::cout << LIME "int:    \t" << i << RST << std::endl;
	}
	else
		std::cout << REDD "int:    \t" << "impossible" RST << std::endl;
	
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f << "f" RST << std::endl;

	d = static_cast<double>(f);
	std::cout << ORNG "double: \t" << d << RST << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////

// DOUBLE /////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty()) return (false);

	size_t	i = 0;
	bool	digitBeforeDecimal = false;
	bool	decimalFound = false;
	bool	digitAfterDecimal = false;
	bool	exponentFound = false;
	bool	digitAfterExponent = false;

	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i == input.size())
		return (false);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);
	// Check chiffres avant le point
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitBeforeDecimal = true;
	// Check point décimal
	if (i < input.size() && input[i] == '.')
	{
		decimalFound = true;
		i++;
	}
	// Check chiffres après le point
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitAfterDecimal = true;
	// Gère un exposant potentiel
	if (i < input.size() && (input[i] == 'e' || input[i] == 'E'))
	{
		exponentFound = true;
		i++;
		// Gère signe après l'exposant
		if (i < input.size() && (input[i] == '+' || input[i] == '-'))
			i++;
		// Check chiffres après l'exposant
		for (; i < input.size() && std::isdigit(input[i]); i++)
			digitAfterExponent = true;
	}

	if (i == input.size() && decimalFound && (digitBeforeDecimal || digitAfterDecimal)
		&& (!exponentFound || (exponentFound && digitAfterExponent)))
		return (true);

	return (false);
}

void	ScalarConverter::toDouble(const std::string &input)
{
	char	c;
	int		i;
	float	f;
	double	d = std::stod(input);

	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(d);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RST << std::endl;
		else
			std::cout << RED1 "char:   \t" << "non displayable" RST << std::endl;
	}
	else
		std::cout << REDD "char:   \t" << "impossible" RST << std::endl;
	
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(d);
		std::cout << LIME "int:    \t" << i << RST << std::endl;
	}
	else
		std::cout << RED1 "int:    \t" << "impossible" RST << std::endl;
	
	f = static_cast<float>(d);
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f << "f" RST << std::endl;

	std::cout << ORNG "double: \t" << d << RST << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////

// SPECIAL ////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isOther(const std::string &input)
{
	const std::string	specials[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };

	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
			return (true);
	}
	return (false);
}

void	ScalarConverter::toOther(const std::string &input)
{
	std::cout << RED1 "char:   \t" << "impossible" RST << std::endl;
	std::cout << RED1 "int:    \t" << "impossible" RST << std::endl;

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << CYAN "float:  \t" << input << RST << std::endl;
		std::string inputFixed = input.substr(0, input.size() - 1);
		std::cout << ORNG "double: \t" << inputFixed << RST << std::endl;
	}
	else
	{
		std::cout << CYAN << "float:  \t" << input << "f" RST << std::endl;
		std::cout << ORNG "double: \t" << input << RST << std::endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
