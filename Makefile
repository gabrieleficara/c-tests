NAME = chess

LIB = $(NAME).a

INC = -I includes

CC = g++ -g

SRC = sources/board.cpp \
	  sources/main.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY : all clean fclean re

$(NAME) :$(OBJ) Makefile
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@$(CC) -o $(NAME) $(LIB)
	@echo "creating chess"

%.o: %.cpp
	$(CC) $(INC) -o $@ -c $<

all : $(NAME)

clean :
	@rm -rf $(OBJ) $(LIB)
	@echo "removing chess objects"

fclean : clean
	@rm -rf $(NAME)
	@echo "removing a nice chess game"

re : fclean all
