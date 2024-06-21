#ifndef _auth_hpp__
#define _auth_hpp__

#include <string>

#include "../def.hpp"

namespace tg_cpp_app {
  class auth
  {
private:
  const client &cli_;

  std::string path_;
public:
    auth( const client &new_cli, const std::string new_path_to_json_dir );

    ~auth();

  };
}

#endif // _auth_hpp__