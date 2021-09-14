all:
	make all -C ./async_frame/echo
	make all -C ./async_frame/action
	make all -C ./mt_alone/
	make all -C ./mt_frame/mt_exec_all_task
	make all -C ./mt_frame/mt_start_thread
	make all -C ./mt_frame/mt_tcpsendrcv
	make all -C ./mt_frame/mt_udpsendrcv
	make all -C ./simple
	
clean:
	make clean -C ./async_frame/echo
	make clean -C ./async_frame/action
	make clean -C ./mt_alone/
	make clean -C ./mt_frame/mt_exec_all_task
	make clean -C ./mt_frame/mt_start_thread
	make clean -C ./mt_frame/mt_tcpsendrcv
	make clean -C ./mt_frame/mt_udpsendrcv
	make clean -C ./simple

all32:
	make -e ARCH=32
