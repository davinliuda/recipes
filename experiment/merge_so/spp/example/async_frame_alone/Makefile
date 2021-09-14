#gcc version
CC  = gcc
CXX = g++
GCCVER := $(shell $(CC) -dumpversion | awk -F. '{ print $$1"."$$2}' )

ASYNC_LIB = ../../../bin/lib/
INC += -I../../include/spp_incl/ -I../../include -I../../async/ -I../../comm  -I./
LIB += -L$(ASYNC_LIB) -lasync_epoll -lsppasyncalone -lqos_client -lcommon -ldl -WL,-rpath,$(ASYNC_LIB)

OBJ_DIR=./obj
LIB_DIR=.

LIB_NAME=async_alone_echo

TARGET = $(LIB_DIR)/$(LIB_NAME)
INSTALL_DIR = ../../bin

OBJ = $(OBJ_DIR)/service.o 

OBJ_EXT= .o
CXXSRC_EXT= .cpp
CSRC_EXT= .c

ifeq ($(ARCH),32)
	CFLAGS += -m32 -march=pentium4
endif
CFLAGS  += -g  -Wall -O2  -D_GNU_SOURCE
CXXFLAGS+=$(CFLAGS)


$(OBJ_DIR)/%$(OBJ_EXT): %$(CXXSRC_EXT)
	@echo
	@echo "Compiling $< ==> $@..."
	@-mkdir -p $(OBJ_DIR)
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@


all:$(TARGET)

$(TARGET) : $(OBJ_DIR)/GetInfo.o $(OBJ_DIR)/GetState.o $(OBJ_DIR)/msg.o  $(OBJ_DIR)/service.o
	@echo
	@echo "Building $^ ==> $@..."
	@-mkdir -p $(LIB_DIR)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIB)

clean:
	@echo
	@echo "Cleaning..." 
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)	

all32:
	make -e ARCH=32
