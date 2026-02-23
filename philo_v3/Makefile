# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 06:39:13 by aphyo-ht          #+#    #+#              #
#    Updated: 2026/02/24 03:07:11 by aphyo-ht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -pthread -g

INCLUDES_DIR	= includes
HEADER_FILES	= includes/philo.h

SRC_DIR			= src/
SRC_FILES		= actions.c cleaner.c inits.c parser.c philo.c \
					routines.c table_utils.c utils.c
SRCS			= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR			= obj/
OBJS			= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

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