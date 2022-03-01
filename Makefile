# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# #                                                                          # #
# #       ███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗     # #
# #       ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝     # #
# #       ██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗       # #
# #       ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝       # #
# #       ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗     # #
# #       ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝     # #
# #                                                                          # #
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #

# --------------------------- Terminal Color Codes --------------------------- #
NC := \033[31;0m
BLD := \033[31;0m\033[1m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

# ---------------------------------------------------------------------------- #

define TITLE
${BLU}
=======================================================================================================
||                                  ,,                                                               ||
||                                `7MM                                                               ||
||                                  MM                                                               ||
|| `7MMpdMAo. `7MM  `7MM  ,pP"Ybd   MMpMMMb.          ,pP"Ybd `7M'    ,A    `MF' ,6"Yb.  `7MMpdMAo.  ||
||   MM   `Wb   MM    MM  8I   `"   MM    MM          8I   `"   VA   ,VAA   ,V  8)   MM    MM   `Wb  ||
||   MM    M8   MM    MM  `YMMMa.   MM    MM          `YMMMa.    VA ,V  VA ,V    ,pm9MM    MM    M8  ||
||   MM   ,AP   MM    MM  L.   I8   MM    MM          L.   I8     VVV    VVV    8M   MM    MM   ,AP  ||
||   MMbmmd'    `Mbod"YML.M9mmmP' .JMML  JMML.        M9mmmP'      W      W     `Moo9^Yo.  MMbmmd'   ||
||   MM                                                                                    MM        ||
||  .JMML.                                     mmmmmmm                                    .JMML.     ||
=======================================================================================================
\n\t\t\t\t\t\t\t\t${BLD} - Created By ${RED}The-Intruder${NC}

endef
export TITLE


# ---------------------------------------------------------------------------- #

SRCS_DIR := ./srcs/
SRCS_LST := init_stack.c
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := ./objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror
CC_OPTS := -Llibs/ft_printf/ -lftprintf \
		-Llibs/libft/ -lft \
		-L. -lps
		
PROJECT := push_swap
MAIN := push_swap.c
HEADER := push_swap.h
NAME := libps.a
EXEC := push_swap

# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re title libs

all: title ${NAME}

intro:
	@echo "\n\n${YEL}Entering ${GRA}${PROJECT}${YEL}'s makefile"
	@echo "----------------------------${NC}"

title:
	@clear
	@echo "$$TITLE"

libs:
	@make -C ./libs/libft/
	@make -C ./libs/ft_printf/

${NAME}: libs intro ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS}
	@echo "\n$(BLU)Archive file $(GRA)$(NAME)$(BLU) created successfully$(NC)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@
	@echo "\n${MGN}Object file ${GRA}$@${MGN} created from ${GRA}$<${MGN}${NC}"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@make -C ./libs/ft_printf/ clean
	@make -C ./libs/libft/ clean
	@rm -rf ${OBJS}
	@echo "${GRA}${PROJECT}${RED}\tobject files deleted${NC}"
	@echo "\n"


fclean: clean
	@make -C ./libs/ft_printf/ fclean
	@make -C ./libs/libft/ fclean
	@rm -rf ${NAME}
	@echo "${GRA}${PROJECT}${RED}\tarchive file ${GRA}${NAME}${RED}\t\tdeleted${NC}"
	@echo "\n"

re: exclean all

bonus: re

# ---------------------------------------------------------------------------- #

exclean: fclean
	@rm -f ${EXEC}
	@echo "Executable file ${GRA}${EXEC}${RED}\n${NC}"

compile: ${HEADER} ${MAIN} ${EXEC}
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${EXEC}