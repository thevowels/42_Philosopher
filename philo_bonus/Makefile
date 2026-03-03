# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 06:39:13 by aphyo-ht          #+#    #+#              #
#    Updated: 2026/03/03 22:42:51 by aphyo-ht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo_bonus
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -pthread -g

INCLUDES_DIR	= includes
HEADER_FILES	= includes/philo_bonus.h

SRC_DIR			= src/
SRC_FILES		= init_bonus.c parser_bonus.c philo_bonus.c utils_bonus.c utils_extra_bonus.c
SRCS			= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR			= obj/
OBJS			= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(GREEN) " Compiling to get $@" $(RESET)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@


all : $(OBJ_DIR) $(NAME)


$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(OBJS) $(HEADER_FILES) Makefile 
	@echo $(GREEN) " Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) $(OBJS) -o $(NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(RED) " - Cleaned!" $(RESET)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED) " - Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re