/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:27 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/22 22:08:43 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl h;

    h.complain("WARNING");
    std::cout << std::endl;
    h.complain("DEBUG");
    std::cout << std::endl;
    h.complain("INFO");
    std::cout << std::endl;
    h.complain("ERROR");
    std::cout << std::endl;

    h.complain("else");
    std::cout << std::endl;
    
    return 0;
}
