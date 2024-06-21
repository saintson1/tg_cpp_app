#include <string>
#include <fstream>
#include <stdexcept>

#include "auth.hpp"

namespace tg_cpp_app
{
    auth::auth( const client &new_cli, const std::string new_path_to_json_dir ):
      cli_(new_cli), path_(new_path_to_json_dir)
    {
      std::ifstream auth_file()
      if ()
      std::runtime_error("auth dir cannot be find");
    };

    ~auth::auth() {};

};