

SRC=capture.c
OBJ=capture.o

APP=test


INCLUDES = -I./

.PONEY:all

all:$(APP) 


$(APP):$(OBJ) 
	@g++  $(OBJ)  -o $@ 

    
%.o:%.cpp
	g++ -c  -fPIC $(INCLUDES) $< -o $@
	
%.o:%.c
	gcc -c $(INCLUDES) $< -o $@    
    
clean:
	@rm -rf $(OBJ) $(APP)
	
	
