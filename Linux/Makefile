CC	=	g++

RM	=	rm -rf

NAME	=	indie_studio

SRCS	=	src/main.cpp \
		src/direction.cpp \
		src/hud.cpp \
		src/menu.cpp \
		src/begin_dante.cpp \
		src/dante_gen.cpp \
		src/ptrmap.cpp \
		src/player.cpp \
		src/collision.cpp \
		src/projectile.cpp \
		src/collisionAtq.cpp

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS 	+=	-std=c++14 -Wextra -Wall -W -Wno-unused-parameter
CPPFLAGS 	+=	-I./include -I./include/irr -I/usr/X11R6/include
LDFLAGS		+=	-L./include -lIrrlicht -L/usr/X11R6/lib64 -lXext
LDFLAGS		+=	-lGL -lXxf86vm -lX11 -lXcursor -pthread
LDFLAGS		+=	./bin/linux-gcc-64/libIrrKlang.so
STATIC_LIB	+=	./include/libIrrlicht.a
SRCS_LIB 	+=	./irrlicht-1.8.4/source/Irrlicht
INCLUDE_LIB	+=	./irrlicht-1.8.4/include
PATH_LIB 	+=	./irrlicht-1.8.4/lib/Linux/libIrrlicht.a

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

install:
ifeq ("$(wildcard $(STATIC_LIB))", "")
		cd $(SRCS_LIB) && make
endif
		cp $(INCLUDE_LIB)/* ./include/irr
		cp $(PATH_LIB) ./include/

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		install

.PHONY:		all clean fclean re
