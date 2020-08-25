##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

ALIAS_DIR		=	alias/
ALIAS_SRC		=	get_alias_file.c \
					alias.c \
					get_alias.c \
					get_command.c \
					display_alias.c \
					unalias.c \
					get_full_command.c \
					check_exist_alias.c \
					get_command_back.c
ALIAS			=	$(addprefix $(ALIAS_DIR), $(ALIAS_SRC))

BUILTINS_DIR	=	builtins/
BUILTINS_SRC	=	cd_cmd/cd.c	\
					exit_cmd/exit.c	\
					env_builtins/env_cmd/init_flags_separator.c	\
					env_builtins/env_cmd/init_env_flags.c	\
					env_builtins/env_cmd/flag_separator.c	\
					env_builtins/env_cmd/env_flags/env_help.c	\
					env_builtins/env_cmd/env_flags/env_null.c	\
					env_builtins/env_cmd/env_flags/env_unset.c	\
					env_builtins/env_cmd/env_flags/env_version.c	\
					env_builtins/env_cmd/env_flags/env.c	\
					env_builtins/setenv_cmd/setenv.c	\
					env_builtins/setenv_cmd/add_env.c	\
					env_builtins/setenv_cmd/change_env.c	\
					env_builtins/setenv_cmd/check_setenv.c	\
					env_builtins/setenv_cmd/env_add.c	\
					env_builtins/unsetenv_cmd/unsetenv.c \
					echo/echo.c
BUILTINS 		=	$(addprefix $(BUILTINS_DIR), $(BUILTINS_SRC))

ENV_PARSING_DIR	=	env_parsing/
ENV_PARSING_SRC	=	get_cwd.c	\
					get_old_path.c	\
					get_usr.c	\
					get_var.c
ENV_PARSING 	=	$(addprefix $(ENV_PARSING_DIR), $(ENV_PARSING_SRC))

FREE_DIR		=	free/
FREE_SRC		=	free_essentials.c	\
					free_flags.c \
					free_linked_list.c \
					free_exec.c \
					free_alias.c
FREE 			=	$(addprefix $(FREE_DIR), $(FREE_SRC))

INIT_STRUCTS_DIR	=	init_structs/
INIT_STRUCTS_SRC	=	init_essentials.c	\
						init_exec_info.c	\
						init_alias.c
INIT_STRUCTS		=	$(addprefix $(INIT_STRUCTS_DIR), $(INIT_STRUCTS_SRC))

HISTORY_DIR		=	history/
HISTORY_SRC		=	history_controller.c \
					call_middleman.c \
					check_command_errors.c \
					check_all_args.c \
					history_handler/history_add_element.c \
					history_handler/history_display.c \
					history_handler/free_all_elements.c \
					history_handler/get_last_id.c \
					history_handler/save_history_on_file.c \
					history_handler/get_current_time.c \
					history_handler/add_element_on_first_position.c \
					history_handler/check_and_delete_repeated.c \
					history_handler/add_new_element_from_gnl.c \
					history_handler/init_history_element.c \
					history_file_manager/check_history_file.c \
					history_file_manager/grab_all_elements.c \
					history_file_manager/check_and_ignore_repeated.c \
					history_file_manager/get_elements_from_file.c
HISTORY			=	$(addprefix $(HISTORY_DIR), $(HISTORY_SRC))

SRC_DIR 		=	src/
SRC_SRC 		=	$(ALIAS) \
					$(BUILTINS)	\
					$(ENV_PARSING)	\
					$(FREE)	\
					$(INIT_STRUCTS)	\
					$(HISTORY) \
					executor.c	\
					checks.c	\
					interpreter.c	\
					prompt.c	\
					main_loop.c	\
					42sh.c	\
					main.c
SRC 			=	$(addprefix $(SRC_DIR), $(SRC_SRC))

OBJ 	=	$(SRC:.c=.o)

LIB_DIR 	=	my_lib/

CC 		=	cc

LIB 	= 	-L $(LIB_DIR) -lmy

RM 		=	rm -f

GCC 	= 	-g -o

CFLAGS	+=	-I include
CFLAGS 	+= 	-Wall -Wextra
CFLAGS 	+= 	-Wpedantic -Wno-long-long
CFLAGS 	+= 	-Werror -g3

NAME	= 	42sh

all:		$(NAME)

$(NAME):	$(OBJ)
			cd $(LIB_DIR) ; $(MAKE) -f Makefile
			$(CC) $(GCC) $(NAME) $(OBJ) $(LIB)

clean:
			$(RM) $(OBJ)
			cd $(LIB_DIR) ; $(MAKE) -f Makefile clean

fclean:		clean
			$(RM) $(NAME)
			cd $(LIB_DIR) ; $(MAKE) -f Makefile fclean

re:			fclean all
			cd $(LIB_DIR) ; $(MAKE) -f Makefile re
