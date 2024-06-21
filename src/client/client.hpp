#ifndef _client_hpp__
#define _client_hpp__

#include "../def.hpp"
#include <string>

namespace tg_cpp_app {
  class client
  {
private:
  void *instance_ptr_;
public:
    client();
    client( const client &new_client );
    client( client &&new_client );

    client & operator=( const client &new_client );
    client & operator=( client &&new_client );

    ~client();

    nlohmann::json send( std::string request );
  };
}

#endif // _client_hpp__