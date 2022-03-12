# a sample Makefile

CC = clang
CFLAGS = -g -Wall --std=c99 -DNDEBUG

PROG = test
HDRS = map.h table.h regions.h
SRCS = test.c map.c table.c regions.c

OBJDIR = object
OBJS = $(OBJDIR)/test.o $(OBJDIR)/map.o $(OBJDIR)/table.o $(OBJDIR)/regions.o

# compiling rules

# WARNING: *must* have a tab before each definition
$(PROG): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

$(OBJDIR)/test.o: test.c $(HDRS)
	$(CC) $(CFLAGS) -c test.c -o $(OBJDIR)/test.o

$(OBJDIR)/map.o: map.c $(HDRS)
	$(CC) $(CFLAGS) -c map.c -o $(OBJDIR)/map.o

$(OBJDIR)/table.o: table.c $(HDRS)
	$(CC) $(CFLAGS) -c table.c -o $(OBJDIR)/table.o

$(OBJDIR)/regions.o: regions.c $(HDRS)
	$(CC) $(CFLAGS) -c regions.c -o $(OBJDIR)/regions.o

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -f $(PROG) $(OBJS)
#	rmdir $(OBJDIR)
