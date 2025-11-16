CC      = gcc
CFLAGS  = -Wall -fPIC -Iinclude

SRCDIR  = src
OBJDIR  = obj
LIBDIR  = lib
BINDIR  = bin

LIBNAME = libmyops.so.1.0
LIBSO   = $(LIBDIR)/$(LIBNAME)

APP_SRC = $(SRCDIR)/myapp.c
APP_OBJ = $(OBJDIR)/myapp.o

OPS_SRCS = $(SRCDIR)/myadd.c \
           $(SRCDIR)/mysub.c \
           $(SRCDIR)/mymul.c \
           $(SRCDIR)/mydiv.c \
           $(SRCDIR)/mymod.c \
           $(SRCDIR)/mypow.c

OPS_OBJS = $(OPS_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(BINDIR)/myapp

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBSO): $(OPS_OBJS)
	@mkdir -p $(LIBDIR)
	$(CC) -shared -Wl,-soname,libmyops.so.1 -o $(LIBSO) $(OPS_OBJS)
	ln -sf $(LIBNAME) $(LIBDIR)/libmyops.so.1
	ln -sf libmyops.so.1 $(LIBDIR)/libmyops.so

$(BINDIR)/myapp: $(APP_OBJ) $(LIBSO)
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $(APP_OBJ) -L$(LIBDIR) -lmyops -Wl,-rpath,'$$ORIGIN/../lib'

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(LIBDIR)/libmyops.so*
	rm -f $(BINDIR)/myapp
