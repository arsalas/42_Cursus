/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:41:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/05 18:42:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
	Karen karen;
	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	return(0);
}