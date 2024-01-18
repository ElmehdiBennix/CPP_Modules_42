# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:38 by ebennix           #+#    #+#              #
#    Updated: 2024/01/18 11:02:37 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := megaphone

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

FILES := megaphone.cpp

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
