CFLAGS = -Wall -fsanitize=address
SRCDIR = .
OBJDIR = fichier.o
BINDIR = executable

SRCS = $(filter-out $(SRCDIR)/main.c, $(wildcard $(SRCDIR)/*.c))

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
EXEC = $(BINDIR)/bataille

LIBRARY = $(BINDIR)/libstat.a

all: $(LIBRARY) $(EXEC)

$(LIBRARY): $(OBJS)
	@mkdir -p $(BINDIR)
	ar rcs $@ $(OBJS)

$(EXEC): $(OBJDIR)/main.o $(LIBRARY)
	gcc $(CFLAGS) -o $@ $< -L$(BINDIR) -lstat

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

