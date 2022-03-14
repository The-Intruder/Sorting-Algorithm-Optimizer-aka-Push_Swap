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
CC_FLAGS := -Wall -Wextra -Werror -Ofast -march=native -fno-signed-zeros -fno-trapping-math
CC_OPTS := -Llibs/libft -lft -Llibs/ft_printf -lftprintf -L. -lps

NB_LIST := -66 -352 -310 295 -456 218 380 215 188 49 -422 -213 -493 497 407 -425 -302 104 -355 453 -148 -429 -238 -498 -154 208 -428 -371 -95 186 -332 29 273 -386 173 140 33 472 152 341 409 -141 379 79 -402 373 489 -434 -490 178 415 -133 -325 -489 -384 221 -411 261 -181 133 -458 40 -216 138 -175 -132 351 -218 154 430 230 -73 20 23 322 214 -63 32 285 -27 -273 225 17 -108 -240 115 -419 46 -160 187 70 -254 431 243 308 353 127 194 374 -442

PROJECT := push_swap
MAIN := push_swap.c
HEADER := push_swap.h
NAME := libps.a
EXEC := push_swap

# ---------------------------------------------------------------------------- #
SRCS_DIR := srcs/
SRCS_LST := init_stack.c error_handling.c stack_ops_utils.c stack_ops_main.c \
			misc_utils.c long_incr_sub.c testing_functions.c \
			lis_filtering.c sorting_algo_i.c sorting_algo_ii.c 
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title libs exclean intro compile

all: title ${NAME}

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

compile: re ${HEADER} ${MAIN}
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${EXEC}

execute: compile ${EXEC}
	@./${EXEC} ${NB_LIST}
	@make exclean >> /dev/null

fclean: clean
	@make -C libs/ft_printf/ fclean
	@make -C libs/libft/ fclean
	@rm -rf ${NAME}
	@echo "${GRA}${PROJECT}${RED}\tarchive file ${GRA}${NAME}${RED}\t\thas been deleted${NC}"
	@echo "\n"

exclean: fclean
	@rm -f ${EXEC}
	@echo "${GRA}${EXEC}${RED}\texecutable file has been deleted\n${NC}"

re: fclean all

intro:
	@echo "\n${YEL}Entering ${GRA}${PROJECT}${YEL}'s makefile"
	@echo "----------------------------${NC}"

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- #
