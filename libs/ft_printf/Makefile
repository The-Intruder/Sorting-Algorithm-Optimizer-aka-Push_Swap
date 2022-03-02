# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 17:31:07 by mnaimi            #+#    #+#              #
#    Updated: 2021/12/12 17:31:55 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror

SRCS := ft_printf_utils_getdata.c ft_printf_utils_isdata.c \
	ft_printf_utils_misc_1st.c ft_printf_utils_misc_2nd.c \
	ft_printf_utils_misc_3rd.c ft_printf_utils_misc_4th.c \
	ft_printf_utils_processdata_1st.c ft_printf_utils_processdata_2nd.c \
	ft_printf.c

OBJS := $(SRCS:%.c=%.o)

PROJECT := ft_printf
HEADER := ft_printf.h
NAME := libftprintf.a

.PHONY: all clean fclean re title

all: title ${NAME}

title:
	@echo "\n${YEL}Entering ${GRA}${PROJECT}${YEL}'s makefile"
	@echo "----------------------------${NC}"

$(NAME): $(OBJS) ${HEADER}
	@ar rcs $(NAME) $(OBJS)
	@echo "$(BLU)Archive file $(GRA)$(NAME)$(BLU) created successfully$(NC)"

%.o: %.c
	@$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "${MGN}Object file ${GRA}$@${MGN} created from ${GRA}$<${MGN}${NC}"

clean:
	@rm -if ${OBJS}
	@echo "${GRA}${PROJECT}${RED}\tobject files deleted${NC}"

fclean:
	@rm -if ${NAME}
	@echo "${GRA}${PROJECT}${RED}\tarchive file ${GRA}${NAME}${RED}\tdeleted${NC}"

re: fclean all

