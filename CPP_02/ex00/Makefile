# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 13:58:53 by ebennix           #+#    #+#              #
#    Updated: 2023/12/30 00:44:34 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := test00

CPP := clang++

CPPFLAGS := -Wall -Wextra -Werror

INC :=fixed.hpp

FILE := fixed

SRC := $(FILE:=.cpp)

OBJ :=$(SRC:.cpp=.o)

################################################################################ 

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) main.cpp -o $(EXE)

%.o: %.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

################################################################################ 

.PHONY: all clean fclean re