/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:25:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/03 22:32:14 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	std::cout << std::endl;

	if (argc < 2)
		std::cout << YLLW "Usage: ./convert <value_to_cast1> <value_to_cast2> ..." RST << std::endl;
	
	int	i = 1;
	
	while (argv[i])
	{
		std::cout << GRY1 "############## OUTPUT " << i << " ##############" RST << std::endl;
		std::cout << ITAL GRY1 "user input:\t\"" << argv[i] << "\"" RST << std::endl;
		
		if (argv[i][0])
			ScalarConverter::convert(argv[i++]);
		else
			std::cout << RUBY "Argument " << i++ << " is empty." RST << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
