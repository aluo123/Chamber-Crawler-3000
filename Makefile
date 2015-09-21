# Universal makefile for single C++ program
#
# Use gcc flag -MMD (user) or -MD (user/system) to generate dependences among source files.
# Use make default rules for commonly used file-name suffixes and make variables names.
#
# % make [ a.out ]

########## Variables ##########
CXX = g++					# compiler
CXXFLAGS = -g -Wall -MMD			# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS = main.o character.o player.o shade.o drow.o troll.o vampire.o goblin.o enemy.o human.o dwarf.o elf.o orc.o halfling.o merchant.o stairs.o item.o \
gold.o smallgold.o normalgold.o potion.o rhpot.o bapot.o phpot.o bdpot.o wdpot.o wapot.o cell.o tile.o passage.o wall.o floor.o game.o controller.o textdisplay.o \
dragon.o
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"
EXEC = cc3k					# executable name

########## Targets ##########

.PHONY : clean					# not file names

${EXEC} : ${OBJECTS}				# link step
	${CXX} ${CXXFLAGS} $^ -o $@		

${OBJECTS} : ${MAKEFILE_NAME}			

# make implicitly generates rules to compile C++ files that generate .o files

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}	

