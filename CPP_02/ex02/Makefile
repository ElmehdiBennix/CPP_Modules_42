# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 13:58:53 by ebennix           #+#    #+#              #
#    Updated: 2023/12/31 00:24:49 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := test02

CPP := clang++

CPPFLAGS := -Wall -Wextra -Werror

INC :=fixed.hpp

FILE := fixed

SRC := $(FILE:=.cpp)

OBJ :=$(SRC:.cpp=.o)

################################################################################ 

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(CPPFLAGS) main.cpp $(OBJ) -o $(EXE)

%.o: %.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

################################################################################ 

.PHONY: all clean fclean re