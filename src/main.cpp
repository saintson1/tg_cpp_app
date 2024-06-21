#include <string>
#include <iostream>
#include <fstream>

#include "def.hpp"

int main( int argv, char **argc )
{
  tg_cpp_app::client new_client;

  std::ifstream filee("E:/visual_studio/tg_cpp_app/external/auth/auth_0.json");
  nlohmann::json req;

  if (filee.is_open())
    filee >> req;
  filee.close();

  nlohmann::json ans = new_client.send(req.dump());

  return 0;
}