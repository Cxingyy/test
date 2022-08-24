TARGET := run
OBJS :=main.o add.o address_book.o show.o search.o delete.o revise.o clear.o
CFLAGS := -c -o 
CFLAGSs := -o 
RM := rm -rf

$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(CFLAGSs) $(TARGET)
%o:%c
	$(CC) $< $(CFLAGS) $@
clean-o:
	$(RM) $(OBJS) 
clean-all:
	$(RM) $(OBJS) $(TARGET)	