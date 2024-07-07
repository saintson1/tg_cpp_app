#include <string>
#include <iostream>
#include <fstream>

#include "def.hpp"
#include "tools/file/json/json.hpp"
#include "tools/file/file.hpp"

int main( int argv, char **argc )
{
  tg_cpp_app::client new_client;

  std::ifstream filee("E:/visual_studio/tg_cpp_app/external/auth/auth_0.json");
  nlohmann::json req;

  if (filee.is_open())
    filee >> req;
  filee.close();

  nlohmann::json ans = new_client.send(req.dump());

  tg_cpp_app::json new_json(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/auth"));


  std::cout << "\n\n\n\n\n\n" << new_json.to_string() << "\n\n\n\n\n\n";

  tg_cpp_app::json test_json(
    R"({
        "_":
        {
          "_": "dfsdfsd",
          "sub": true
        },
        "this": true
      })"
  );

  test_json["test_new_fild"];
  test_json["test_new_fild_add_value_0"] = 34;
  test_json["test_new_fild_add_value_1"] = true;
  test_json["test_new_fild_add_value_2"] = "test_value";
  test_json["test_new_fild_add_value_3"] = {1,3,4,5,6,4};
  // test_json["test_new_fild_add_value_4"] = new_json;

  return 0;
}