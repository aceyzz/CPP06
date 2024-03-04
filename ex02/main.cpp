/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:05:31 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/04 15:15:31 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"

Base*	generate(void)
{
	int	choice = rand() % 3;

	switch (choice)
	{
		case (0): return new A();
		case (1): return new B();
		default: return new C();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL) std::cout << BLUE "- A -" RST << std::endl;
	else if (dynamic_cast<B*>(p) != NULL) std::cout << CYAN "- B -" RST << std::endl;
	else if (dynamic_cast<C*>(p) != NULL) std::cout << MAGN "- C -" RST << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << LIME "- A -" RST << std::endl;
	}
	catch (const std::bad_cast &e) { std::cout << REDD << "NOT A" << std::endl; }
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << LIME "- B -" RST << std::endl;
	}
	catch (const std::bad_cast &e) { std::cout << REDD << "NOT B" << std::endl; }
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << LIME "- C -" RST << std::endl;
	}
	catch (const std::bad_cast &e) { std::cout << REDD << "NOT C" << std::endl; }
}

int	main(void)
{
	std::cout << CLRALL;

	srand(static_cast<unsigned int>(time(0))); // Initialise le générateur de nombres aléatoires.

	Base* instances[NB_INSTANCES];
	
	// Génère NB_INSTANCES random de A, B, ou C.
	for (int i = 0; i < NB_INSTANCES; ++i)
		instances[i] = generate();

	// Identifie le type de chaque instance via un pointeur.
	std::cout << GRY1 "Identify pointer:" RST<< std::endl;
	for (int i = 0; i < NB_INSTANCES; ++i)
		identify(instances[i]);
	std::cout << std::endl;

	// Identifie le type de chaque instance via une référence.
	std::cout << GRY1 "Identifiy reference:" RST << std::endl;
	for (int i = 0; i < NB_INSTANCES; ++i)
	{
		identify(*instances[i]);
		std::cout << std::endl;
	}

	for (int i = 0; i < NB_INSTANCES; ++i)
		delete instances[i];

	return (0);
}
