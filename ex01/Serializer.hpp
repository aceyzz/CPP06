/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:12:28 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/04 13:13:17 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdint>

typedef struct Data
{
	std::string	valStr;
	int			valInt;
}		Data;

class	Serializer
{
	public:
		static uintptr_t 	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer& operator=(const Serializer &src);
		~Serializer();
};
