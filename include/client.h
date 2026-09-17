#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <unistd.h>

namespace HTTP_Client {
  /** Enumerates the various HTTP versions */
  enum VERSION {
    ZERO_NINE,
    ONE_ZERO,
    ONE_ONE,
    TWO_ZERO,
    THREE_ZERO
  };

  /** Enumerates the various HTTP methods */
  enum METHOD {
    DELETE,
    GET,
    OPTIONS,
    PUT,
    POST
  };

  /** The actual Client class that does all the work. */
  class Client {
  public:
    Client(VERSION v): v_(v){}
    void connect();
  private:
    VERSION v_;
  };

} // HTTP_client
#endif // CLIENT_H_
