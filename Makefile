##
## EPITECH PROJECT, 2024
## NOP
## File description:
## void;
##

SRC  = src/*.c
LIBS = -l m
NAME = connect
DEFAULTARGS  = ""

compile:
	@ gcc -g -Wall -Wextra $(SRC) $(LIBS) -o $(NAME)

run: compile
	@ ./$(NAME) $(DEFAULTARGS)
	@ rm $(NAME)

valgrind: compile
	@valgrind -s --show-leak-kinds=none \
		--track-origins=yes \
		--leak-check=full \
		--error-limit=no \
	./$(NAME) $(DEFAULTARGS)
	@ rm $(NAME)

clean:
	@ rm -fr *.o

fclean: clean
	@ rm -f $(NAME)

re: fclean compile

kronk:
	@ echo "Oh ouais."
