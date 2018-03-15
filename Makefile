

SRC=capture.c FrameData.cpp FrameQueue.cpp librtmp_send264.cpp
OBJ=capture.o FrameData.o FrameQueue.o librtmp_send264.o

APP=test


INCLUDES = -I./

.PONEY:all

all:$(APP) 


$(APP):$(OBJ) 
	@g++  $(OBJ) -lyuv -lx264 -lpthread ./lib/librtmp.a ./lib/libssl.a ./lib/libcrypto.a -ldl -lm -lz -o $@ 

    
%.o:%.cpp
	g++ -c  -fPIC $(INCLUDES) $< -o $@
	
%.o:%.c
	gcc -c $(INCLUDES) $< -o $@    
    
clean:
	@rm -rf $(OBJ) $(APP)
	
	
