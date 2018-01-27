##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## BSQ maker
##

SRC_DIR	=	src

SRC		=	$(SRC_DIR)/main.c	\
			$(SRC_DIR)/loop.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

CPPFLAGS	=	-I./include/

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc -O3 $(OBJ) -o $(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	clean fclean re
