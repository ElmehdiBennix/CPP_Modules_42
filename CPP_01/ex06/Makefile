# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:11:36 by ebennix           #+#    #+#              #
#    Updated: 2023/11/07 16:20:28 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Harl_2.0

CC := c++ 

HEADER := Harl.hpp

CPPFLAGS := -std=c++98 -Wall -Wextra -Werror

SRC := main \
	   Harl \

FILES := $(SRC:=.cpp)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf

################################################################################

all : $(EXE)

$(EXE) : $(OBJ) 
	$(CC)  $(OBJ) -o $(EXE)

%.o : %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c -o $@ $< 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git : fclean
	sh ../push.sh

################################################################################

.PHONY : all clean fclean re git
