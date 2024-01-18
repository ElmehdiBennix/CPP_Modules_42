# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:11:36 by ebennix           #+#    #+#              #
#    Updated: 2024/01/18 09:42:45 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := replace

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

SRC := main \

FILES := $(SRC:=.cpp)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf

################################################################################

all : $(EXE)

$(EXE) : $(OBJ) 
	$(CPP)  $(OBJ) -o $(EXE)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $< 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git : fclean
	sh ../../push.sh

################################################################################

.PHONY : all clean fclean re git
