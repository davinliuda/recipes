#!/bin/sh

function print_usage()
{
    echo "usage: $0 ServerName Port"
    echo "  ServerName: async_action async_echo mt_alone mt_exec_all_task mt_start_thread mt_tcpsendrcv mt_udpsendrcv simple"
}

# check input parameters
if [ $# != 2 ] ; then
    print_usage
    exit 1; 
fi

if [ -e ../bin/spp.pid ]
then
   echo "spp_ctrl is running? Check it now~ OR delete ./spp.pid"
fi

server_name=$1

# copy case config file to outer etc folder
case $1 in
    async_action ) etc_path=async/action;;
    async_echo ) etc_path=async/echo;;
    mt_exec_all_task ) etc_path=mt_frame/mt_exec_all_task;;
    mt_start_thread ) etc_path=mt_frame/mt_start_thread;;
    mt_tcpsendrcv ) etc_path=mt_frame/mt_tcpsendrcv;;
    mt_udpsendrcv ) etc_path=mt_frame/mt_udpsendrcv;;
    simple ) etc_path=simple;;
    * ) print_usage;exit 1;
esac
cp etc/${etc_path}/* ../etc

# replace the default port to specify port
sed -i "/address:/s/9902/$2/" ../etc/service.yaml

# transform yaml config file to xml config file
cd ../bin
./yaml_tool x

# start spp service
./spp_ctrl ../etc/spp_ctrl.xml

sleep 5s

if ps aux | grep -q spp_ctrl
then
    echo "start spp on port $2 success"
else
    echo "start spp on prot $2 failed"
fi

