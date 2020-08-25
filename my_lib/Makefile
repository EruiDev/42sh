##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MY_ARR_DIR	=	my_arr/
MY_ARR_SRC	=	my_arrdup.c	\
				my_arrlen.c	\
				my_add_str_to_arr.c
MY_ARR 		=	$(addprefix $(MY_ARR_DIR), $(MY_ARR_SRC))

MY_STR_DIR	=	my_str/
MY_STR_SRC	=	my_revstr.c	\
				my_str_to_word_array.c	\
				my_str_to_array.c \
				my_assembler.c \
				my_strcat.c \
				clean_string.c \
				my_strcnt.c	\
				my_isalpha.c \
				nbr_to_str.c
MY_STR 		=	$(addprefix $(MY_STR_DIR), $(MY_STR_SRC))

MY_PUT_DIR	=	my_put/
MY_PUT_SRC	=	my_put_nbr.c	\
				my_putarr.c	\
				my_putchar.c	\
				my_putstr.c
MY_PUT 		=	$(addprefix $(MY_PUT_DIR), $(MY_PUT_SRC))

MY_FREE_DIR	=	my_free/
MY_FREE_SRC	=	my_free_arr.c	\
				my_free_str.c
MY_FREE		=	$(addprefix $(MY_FREE_DIR), $(MY_FREE_SRC))

SRC_DIR	=	src/
SRC_SRC	=	$(MY_ARR)	\
			$(MY_STR)	\
			$(MY_FREE)	\
			$(MY_PUT)	\
			$(GET_NEXT_LINE) \
			get_next_line.c \
			my_getnbr.c
SRC		=	$(addprefix $(SRC_DIR), $(SRC_SRC))

OBJ		=	$(SRC:.c=.o)

RM 		=	rm -f

LIB_CC	=	ar rc

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
			$(LIB_CC) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re : 		fclean all