#include "auth.hpp"

#include <string>

#include "../tools/tools_def.hpp"

namespace tg_cpp_app
{
    auth::auth( client & new_cli, const std::string & new_path_to_json_dir ) : cli_(new_cli), requests_(file(new_path_to_json_dir))
    {
      for (auto beg = requests_.begin(), end = requests_.end(); beg != end; ++beg)
        cli_.send(beg->dump());
    };

    auth::~auth() {  };

};