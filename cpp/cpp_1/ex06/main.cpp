/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:41:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 18:58:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Missing filter" << std::endl;
		return (1);
	}
	Karen karen(argv[1]);
	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	return (0);
}