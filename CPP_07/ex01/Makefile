EXE := Exo

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Wshadow
# -werror

HEADERS := iter.hpp

FILES := main.cpp

OBJ := $(FILES:.cpp=.o)

################################################################################

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

git :
	sh ../../push

################################################################################ 

.PHONY: clean fclean re git
