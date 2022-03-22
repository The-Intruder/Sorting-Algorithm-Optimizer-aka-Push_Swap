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
NC  := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

# ---------------------------------------------------------------------------- #

define TITLE
${RED}
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
|| .JMML.                                     mmmmmmm                                    .JMML.      ||
||                                                                                                   ||
=======================================================================================================
\n\t\t\t\t\t\t\t\t${GRA} - Created By ${BLU}The-Intruder${NC}
endef
export TITLE

# ---------------------------------------------------------------------------- #
CC := gcc
CC_FLAGS := -Wall -Wextra -Werror \
	-Ofast -march=native -fno-signed-zeros -fno-trapping-math
CC_OPTS := -Llibs/libft -lft -Llibs/ft_printf -lftprintf -L. -lps

NB_LIST := 1299749835 -2123657034 1143701706 1341364441 612786098

PROJECT := push_swap
MAIN := push_swap.c
HEADER := push_swap.h
NAME := libps.a
EXEC := push_swap

# ---------------------------------------------------------------------------- #
SRCS_DIR := srcs/
SRCS_LST := init_stack.c error_handling.c stack_ops_utils.c stack_ops_main.c \
	misc_utils_i.c misc_utils_ii.c lis_algo.c lis_misc.c lis_filtering.c \
	testing_functions.c sorting_algo_i.c sorting_algo_ii.c sorting_algo_iii.c 
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title libs exclean intro compile

all: title compile

libs:
	@make -C libs/libft/
	@make -C libs/ft_printf/

${NAME}: libs intro ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS}
	@echo "$(BLU)Archive file $(GRA)$(NAME)$(BLU) created successfully$(NC)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@
	@echo "${MGN}Object file ${GRA}$@${MGN} created from ${GRA}$<${MGN}${NC}"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@make -C libs/ft_printf/ clean
	@make -C libs/libft/ clean
	@rm -rf ${OBJS}
	@echo "${GRA}${PROJECT}${RED}\tobject files have been deleted${NC}"
	@echo "\n"

exclean:
	@rm -f ${EXEC}
	@echo "${GRA}${EXEC}${RED}\texecutable file has been deleted\n${NC}"

fclean: clean exclean
	@make -C libs/ft_printf/ fclean
	@make -C libs/libft/ fclean
	@rm -rf ${NAME}
	@echo "${GRA}${PROJECT}${RED}\tarchive file ${GRA}${NAME}${RED}\t\thas been deleted${NC}"
	@echo "\n"

re: fclean all

compile: ${NAME} ${HEADER} ${MAIN}
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${EXEC}

recompile: exclean all

execute: ${EXEC}
	@./${EXEC} ${NB_LIST}
	@./${EXEC} ${NB_LIST} | ./checker_Mac ${NB_LIST}
	@./${EXEC} ${NB_LIST} | wc -l


intro:
	@echo "\n${YEL}Entering ${GRA}${PROJECT}${YEL}'s makefile"
	@echo "----------------------------${NC}"

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- #
