# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:38 by ebennix           #+#    #+#              #
#    Updated: 2023/11/02 02:35:31 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := BraiiiiiiinnnzzzZ

CC := c++ -std=c++98

HEADER := Zombie.hpp

CPPFLAGS := -Wall -Wextra -Werror

SRC := main \
	   Zombie	\
	   newZombie \
	   randomChump \

FILES := $(SRC:=.CPP)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf

################################################################################

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC)  $(OBJ) -o $(EXE) 

%.o : %.c $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

################################################################################

.PHONY : all clean fclean re
