/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:51:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/04 13:06:29 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// PRIVATE COPLIEN'S (not instanciable)
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &src) { (void)src; }
Serializer& Serializer::operator=(const Serializer &src) { (void)src; return (*this); }
Serializer::~Serializer() {}

// MANDATORY MEMBERS
uintptr_t	Serializer::serialize(Data* ptr)
{	
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
