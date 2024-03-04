/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:43:10 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/04 13:46:14 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Serializer.hpp"

inline void	printDebug(const std::string &mess)
{
	std::cout << GRY1 "*************************************" << std::endl;
	std::cout << mess << std::endl;
	std::cout << "*************************************" RST << std::endl;
}

int	main(void)
{
	Data	A;
	Data	B;
	Data	*C;

	uintptr_t result;

	std::cout << CLRALL;

	printDebug("INIT DATA A & DATA B & DATA C");
	std::cout << CYAN "A et B ont des valeurs distinctes" << std::endl;
	std::cout << "C pointe vers B" RST << std::endl;
	A.valInt = 42;
	A.valStr = "Deux fois vingt-et-un";
	B.valInt = 69;
	B.valStr = "Six-Neuf la trique";
	C = &B;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF A");
	std::cout << GRY2 "A - int value :\t" GOLD << A.valInt << RST << std::endl;
	std::cout << GRY2 "A - str value :\t" GOLD << A.valStr << RST << std::endl;
	std::cout << GRY2 "A - adr value :\t" GOLD << &A << RST << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF B");
	std::cout << GRY2 "B - int value :\t" MAGN << B.valInt << RST << std::endl;
	std::cout << GRY2 "B - str value :\t" MAGN << B.valStr << RST << std::endl;
	std::cout << GRY2 "B - adr value :\t" MAGN << &B << RST << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF C");
	std::cout << GRY2 "C - int value :\t" LIME << C->valInt << RST << std::endl;
	std::cout << GRY2 "C - str value :\t" LIME << C->valStr << RST << std::endl;
	std::cout << GRY2 "C - adr value :\t" LIME << C << RST << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "///// SERIALIZE A /////" RST << std::endl;
	result = Serializer::serialize(&A);
	std::cout << GRY2 "Result value :\t" CYAN << result << RST << std::endl;
	std::cout << std::endl;

	// printDebug("DESERIALIZE C");
	std::cout << CYAN "//// DESERIALIZE C ////" RST << std::endl;
	C = Serializer::deserialize(result);
	std::cout << GRY2 "Result value :\t" CYAN << result << RST << std::endl;
	std::cout << std::endl;
	
	printDebug("PRINT VALUES OF A");
	std::cout << GRY2 "A - int value :\t" GOLD << A.valInt << RST << std::endl;
	std::cout << GRY2 "A - str value :\t" GOLD << A.valStr << RST << std::endl;
	std::cout << GRY2 "A - adr value :\t" GOLD << &A << RST << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF B");
	std::cout << GRY2 "B - int value :\t" MAGN << B.valInt << RST << std::endl;
	std::cout << GRY2 "B - str value :\t" MAGN << B.valStr << RST << std::endl;
	std::cout << GRY2 "B - adr value :\t" MAGN << &B << RST << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF C");
	std::cout << GRY2 "C - int value :\t" LIME << C->valInt << RST << std::endl;
	std::cout << GRY2 "C - str value :\t" LIME << C->valStr << RST << std::endl;
	std::cout << GRY2 "C - adr value :\t" LIME << C << RST << std::endl;
	std::cout << std::endl;

	if (&A == C)
		std::cout << CYAN "✅ Maintenant C pointe vers A ✅" RST << std::endl;
	else
		std::cout << REDD "❌ C DEVRAIT pointer vers A ❌" RST << std::endl;
	std::cout << GRY1 "*************************************" RST << std::endl << std::endl;

	return (0);
}
