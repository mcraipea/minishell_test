# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:21:06 by mcraipea          #+#    #+#              #
#    Updated: 2020/02/10 13:07:49 by mcraipea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_INIT_PROGRAM = ./srcs/init_program/
PATH_EXEC_COMMAND = ./srcs/exec_command/
PATH_COMMANDS = 	./srcs/commands/

SRCS_INIT_PROGRAM =	main.c					\
					main_function.c 		\
					garbage_collector.c 	\
					ft_prompt.c 			\
					parsing_command.c 		\
					split_shell.c			\
					split_shell2.c			\
					len_tabtab.c 			\
					add_arg2.c 				\
					ft_init_env.c			\
					signal.c

SRCS_EXEC_COMMAND = exec_command.c 			\
					ft_execve.c 			\
					is_builtin.c 			\
					exec_command_env.c 		\
					left_chevron.c 			\
					right_chevron.c 		\
					double_left_chevron.c 

SRCS_COMMANDS =		ft_echo.c				\
					ft_export.c 			\
					ft_unset.c 				\
					ft_env.c				\
					ft_cd.c

SRCS0 = $(addprefix $(PATH_INIT_PROGRAM), $(SRCS_INIT_PROGRAM))
SRCS1 = $(addprefix $(PATH_EXEC_COMMAND), $(SRCS_EXEC_COMMAND))
SRCS2 = $(addprefix $(PATH_COMMANDS), $(SRCS_COMMANDS))
HEADERS0 = ./includes/
HEADERS1 = ./libft/includes/
OBJS = $(SRCS0:.c=.o) $(SRCS1:.c=.o) $(SRCS2:.c=.o)
NAME =	minishell
LIB = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -MMD -I $(HEADERS0) -I $(HEADERS1) -Ofast
DPDCS = $(SRCS0:.c=.d) $(SRCS1:.c=.d) $(SRCS2:.c=.d)

all: $(NAME)

-include $(DPDCS)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
	cd ./libft/ && make && cd ..

clean:
	$(RM) $(OBJS) $(LIB) -include $(DPDCS)
	cd ./libft/ && make fclean && cd ..

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re