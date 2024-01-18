/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:12:31 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 15:25:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP__
#define BRAIN_HPP__

class Brain {
    public:
        Brain() {
            std::cout << "Brain constractor called. " << std::endl;
        };
        
        ~Brain() {
            std::cout << "Brain distractor called. " << std::endl;
        };

    protected:
        std::string[100] ideas;
};

#endif