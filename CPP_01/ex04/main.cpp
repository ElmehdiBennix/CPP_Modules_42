/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/23 19:47:58 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "error while openning the file." << std::endl;
        return ;
    }
    std::ofstream outfile(filename + ".replace");
    if (!outfile)
    {
        std::cerr << "unable to create newfile." << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(infile,line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << '\n';
    }
    infile.close();
    outfile.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./replace <filename> <string to replace> <string to replace with>" << std::endl;
        return 1;
    }
    replace(av[1], av[2], av[3]);
    return 0;
}
