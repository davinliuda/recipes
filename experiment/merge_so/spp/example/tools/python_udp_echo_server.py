#!/usr/bin/python
import sys
from socket import *

if len(sys.argv) < 2 :
    print "Usage : %s PORT" % (sys.argv[0])
    sys.exit(1)

us = socket(AF_INET, SOCK_DGRAM, 0)
us.bind(("localhost", int(sys.argv[1])))

#print us
while True:
    s = us.recvfrom(1024)
    #print "received %s" % s[0]
    us.sendto(s[0], s[1])
