CC=gcc
CPP=g++ -g
dbg_option=
monitor_source=./
monitor_include=./
d5000_include=$(HOME)/src/include

COMMONDEF=-D_POSIX_REALTIME_SIGNALS -D_REENTRANT -DLINUX_AIO_NOTIFY_USING_THREAD -DLINUX_USING_QUEUED_IO
CFLAGS=-fpic $(dbg_option) -I $(monitor_include) -I $(d5000_include)
VPATH=$(monitor_source)

PlatformLibs=-lc -lm -lrt -lpthread -ldl -lsam_service -lsend_realdb  -lodb_apiall_lib
D5000_LIB_PATH=$(HOME)/lib
MONITOR_LIBS= -lsend -ldcisg
%.o:%.cpp
	$(CPP) -c  $(CFLAGS) $< -o $@
%.o:%.cc
	$(CPP) -c  $(CFLAGS) $< -o $@

source_objects=main.o\
                 alarmSet.o\
                 AppStruct.o\
                 TableStruct.o\
                 odbsee_app.o\
                 odbsee_tab.o\
                 Util.o\
                 Config.o

object_files=$(source_objects) 

#final_object=control

#all : $(final_object)

.PHONY : all clean rebuild 
	
exe2_real: $(object_files)
	$(CPP) -o $@ $(object_files) -L$(D5000_LIB_PATH) $(MONITOR_LIBS) $(PlatformLibs)
	@rm -rf $(object_files)	
	@echo make ok.

clean :	
	@rm -rf $(object_files)	
#	@rm -rf $(final_object)

rebuild	: clean	all
