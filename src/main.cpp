#include <iostream>
#include <tdlib/td/telegram/td_json_client.h>

int main( int argv, char **argc )
{
  int client_id = td_create_client_id();
  std::cout << client_id << std::endl;

  return 0;
}