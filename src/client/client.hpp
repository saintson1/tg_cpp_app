#ifndef _client_hpp__
#define _client_hpp__

#include <string>

#include "../tools/tools_def.hpp"

namespace tg_cpp_app {
  class client
  {
private:
  void *instance_ptr_;
public:
    client();
    client( const client & new_client );
    client( client && new_client );

    client & operator=( const client & new_client );
    client & operator=( client && new_client );

    ~client();

    void send( const std::string & request );
    json execute( const std::string & request );
    json receive( double timeout );
  };
}

#endif // _client_hpp__