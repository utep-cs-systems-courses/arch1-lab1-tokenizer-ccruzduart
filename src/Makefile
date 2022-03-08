OBJS = tokenizer.o runmain.o history.o

CFLAGS=-g

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenizer *~

run: tokenizer
	./tokenizer
