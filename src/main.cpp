#include <string>
#include <iostream>
#include <fstream>

#include "def.hpp"

#include "tools/tools_def.hpp"

#include "auth/auth.hpp"

void help_dbg_req_func( tg_cpp_app::client & cli, double RECIEV_TIME_OUT = 1 )
{
  tg_cpp_app::json loop_ans = cli.receive(RECIEV_TIME_OUT);

  while(!loop_ans.is_empty())
  {
    std::cout << "ap6 LOGS:::: " << loop_ans.to_string() << "\n\n";
    loop_ans = cli.receive(RECIEV_TIME_OUT);
  }
}


int main( int argv, char **argc )
{
  tg_cpp_app::client new_client;
  double RECIEV_TIME_OUT = 1;
  tg_cpp_app::json loop_ans = new_client.receive(RECIEV_TIME_OUT);

  tg_cpp_app::json set_param_tdlib(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth0.json"));
  tg_cpp_app::json set_auth_num(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth1.json"));
  tg_cpp_app::json check_password(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth2.json"));
  tg_cpp_app::json get_state(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth3.json"));
  tg_cpp_app::json send_code(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth4.json"));
  tg_cpp_app::json set_auth_mail(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth5.json"));
  tg_cpp_app::json req6(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_auth6.json"));
  tg_cpp_app::json req_get_chats(tg_cpp_app::file("E:/visual_studio/tg_cpp_app/external/request_jsons/test/test_get_chats.json"));


  std::cout << "SET PARAM\n";
  new_client.send(set_param_tdlib.to_string());
  help_dbg_req_func(new_client);


  std::cout << "GET STATE\n";
  new_client.send(get_state.to_string());
  help_dbg_req_func(new_client);


  std::cout << "SET NUM\n";
  // new_client.send(set_auth_num.to_string());
  new_client.send(set_auth_num.to_string());
  help_dbg_req_func(new_client);


  std::cout << "SET MAIL\n";
  new_client.send(set_auth_mail.to_string());
  help_dbg_req_func(new_client);


  std::cout << "GET STATE\n";
  new_client.send(get_state.to_string());
  help_dbg_req_func(new_client);


  std::cout << "SEND CODE\n";
  new_client.send(send_code.to_string());
  help_dbg_req_func(new_client);
  // new_client.send(send_code.to_string());
  // help_dbg_req_func(new_client, RECIEV_TIME_OUT + 20);
  // new_client.send(send_code.to_string());
  // help_dbg_req_func(new_client, RECIEV_TIME_OUT + 20);
  // new_client.send(send_code.to_string());
  // help_dbg_req_func(new_client, RECIEV_TIME_OUT + 20);


  // std::cout << "CHECK PASSWORD\n";
  // new_client.send(check_password.to_string());
  // help_dbg_req_func(new_client, RECIEV_TIME_OUT);


  // std::cout << "GET CHATS\n";
  // new_client.send(req_get_chats.to_string());
  // help_dbg_req_func(new_client, RECIEV_TIME_OUT);


  std::cout << "ap6 MESSAGE:::: end_of_program";
  return 0;
}