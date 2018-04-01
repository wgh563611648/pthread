
EXEC=test

objc=$(wildcard *.c)

objo=$(patsubst %.c,%.o,$(objc))

exes=$(patsubst %.o,%,$(objo))




all:$(exes)
	#echo $(exes)
	

$(exes):$(objo)
	gcc $< -o $@ -lpthread
	
$(objo):%.o:%.c
	gcc -c $< -o $@

.PHONEY:clean
clean:
	-rm $(objo) $(exes)
