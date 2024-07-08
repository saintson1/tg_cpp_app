#include <string>
#include <iostream>
#include <fstream>

#include "def.hpp"

#include "tools/tools_def.hpp"

#include "auth/auth.hpp"


int main( int argv, char **argc )
{
  tg_cpp_app::client new_client;

  std::ifstream filee("E:/visual_studio/tg_cpp_app/external/auth/auth_0.json");
  nlohmann::json req;

  if (filee.is_open())
    filee >> req;
  filee.close();

  nlohmann::json ans = new_client.send(req.dump());

  tg_cpp_app::auth auth_test_obj(new_client, "E:/visual_studio/tg_cpp_app/external/request_jsons/auth");

  return 0;
}