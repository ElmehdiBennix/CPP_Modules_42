# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:45:13 by ebennix           #+#    #+#              #
#    Updated: 2023/11/01 20:15:12 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := phonebook

CC := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

HEADER := phonebook.hpp

SRC := Phonebook \
	   Phone	 \
	   Contacts  \

FILES := $(SRC:=.cpp)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf


all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE) 

%.o : %.c $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git :
	sh ../push.sh

.PHONY : all clean fclean re