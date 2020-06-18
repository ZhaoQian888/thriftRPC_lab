// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class ServHandler : virtual public ServIf {
 public:
  ServHandler() {
    // Your initialization goes here
  }

  void put(const Student& s) {
    // Your implementation goes here
    printf("put\n");
    printf("sno=%d sname=%s ssex=%d sage=%d\n", s.sno, s.sname.c_str(), s.ssex, s.sage);
  }

  int32_t icall(const Student& s) {
    // Your implementation goes here
    printf("icall\n");
    printf("sno=%d sname=%s ssex=%d sage=%d\n", s.sno, s.sname.c_str(), s.ssex, s.sage);
    return s.sage;
  }

  void scall(std::string& _return, const Student& s) {
    // Your implementation goes here
    printf("scall\n");
    printf("sno=%d sname=%s ssex=%d sage=%d\n", s.sno, s.sname.c_str(), s.ssex, s.sage);
    _return = s.sname;
  }

  void stcall(Student& _return, const Student& s) {
    // Your implementation goes here
    printf("stcall\n");
    printf("sno=%d sname=%s ssex=%d sage=%d\n", s.sno, s.sname.c_str(), s.ssex, s.sage);
    _return.sno  = s.sno + 1;
    _return.sname = s.sname + "123";
    _return.ssex = s.ssex;
    _return.sage = s.sage + 10;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<ServHandler> handler(new ServHandler());
  ::std::shared_ptr<TProcessor> processor(new ServProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

