#!/usr/bin/env python
"""
Multi-threaded TCP Server
multithreadedServer.py acts as a standard TCP server, with multi-threaded integration, spawning a new thread for each
client request it receives.
This is derived from an assignment for the Distributed Systems class at Bennington College
"""
import sys
from threading import  Thread
from socket import SO_REUSEADDR, SOCK_STREAM, socket, SOL_SOCKET, AF_INET


if len(sys.argv) < 2 :
    print "Usage : %s  PORT" % (sys.argv[0])
    sys.exit(1)

# -------------------------------------------#
########## DEFINE GLOBAL VARIABLES ##########
#-------------------------------------------#


# Create a server TCP socket and allow address re-use
s = socket(AF_INET, SOCK_STREAM)
s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
s.bind(("0.0.0.0", int(sys.argv[1])))

log_file = open('/tmp/python_tcp_server.log', 'a')

# Create a list in which threads will be stored in order to be joined later
threads = []

#---------------------------------------------------------#
########## THREADED CLIENT HANDLER CONSTRUCTION ###########
#---------------------------------------------------------#


class ClientHandler(Thread):
    def __init__(self, address, port, socket):
        Thread.__init__(self)
        self.address = address
        self.port = port
        self.socket = socket

    # Define the actions the thread will execute when called.
    def run(self):
        global log_file
       
        try:
            while 1:
                recv_str = self.socket.recv(1024)
                if len(recv_str) == 0: break
                reverse_str = recv_str[::-1]
                self.socket.send(reverse_str)
        except Exception as e:
            print repr(e)
            log_file.write(repr(e))
            log_file.write('error happaens')
        finally:
            self.socket.close()
            return

#-----------------------------------------------#
########## MAIN-THREAD SERVER INSTANCE ##########
#-----------------------------------------------#

# Continuously listen for a client request and spawn a new thread to handle every request
while 1:

    try:
        # Listen for a request
        s.listen(1)
        # Accept the request
        sock, addr = s.accept()
        sock.settimeout(60)
        # Spawn a new thread for the given request
        newThread = ClientHandler(addr[0], addr[1], sock)
        newThread.start()
        threads.append(newThread)
    except KeyboardInterrupt:
        print "\nExiting Server\n"
        break

# When server ends gracefully (through user keyboard interrupt), wait until remaining threads finish
for item in threads:
    item.join()
