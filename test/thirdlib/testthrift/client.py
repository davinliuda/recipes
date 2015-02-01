import sys

sys.path.append('gen-py/stu/')

import Serv 
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
try:
    # Make socket
    transport = TSocket.TSocket('localhost', 9090)
    # Buffering is critical. Raw sockets are very slow
    transport = TTransport.TFramedTransport(transport)
    # Wrap in a protocol
    protocol = TBinaryProtocol.TBinaryProtocol(transport)
    # Create a client to use the protocol encoder
    client = Serv.Client(protocol)
    # Connect!
    transport.open()
    req = Serv.StudentRequest()
    req.sno = 123
    req.sname = 'liuda'
    req.ssex = 0
    req.ssage = 1231
    while True:
    	result = client.put(req)
    	print "result"
    	print result.ret
    	print result.smsg
        break
    #print user1.name
    # Close!
    transport.close()
except Thrift.TException, tx:
    print '%s' % (tx.message)

