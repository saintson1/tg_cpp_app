#ifndef _auth_hpp__
#define _auth_hpp__

#include <string>

#include "../client/client.hpp"
#include "../tools/tools_def.hpp"

namespace tg_cpp_app {
  class auth
  {
private:
  client & cli_;
  json requests_;

public:
    auth( client & new_cli, const std::string & new_path_to_json_dir );
    ~auth();
  };
}

#endif // _auth_hpp__