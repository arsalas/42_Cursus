/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:41:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 17:20:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	return (0);
}