#include "client.hpp"

#include <stdexcept>
#include <thread>
#include <chrono>

#include "../tools/tools_def.hpp"

namespace tg_cpp_app {
  client::client()
  {
    instance_ptr_ = td_json_client_create();

    if (instance_ptr_ == nullptr)
      throw std::runtime_error("tg client cann't be created");

    td_execute("{\"@type\":\"setLogVerbosityLevel\", \"new_verbosity_level\": 1}");
  };

  client::client( const client &new_client ) : instance_ptr_(new_client.instance_ptr_) {};

  client::client( client &&new_client ) : instance_ptr_(new_client.instance_ptr_)
  {
    new_client.instance_ptr_ = nullptr;
  };

  client & client::operator=( const client &new_client )
  {
    instance_ptr_ = new_client.instance_ptr_;
    return *this;
  };

  client & client::operator=( client &&new_client )
  {
    instance_ptr_ = new_client.instance_ptr_;
    new_client.instance_ptr_ = nullptr;
    return *this;
  };

  client::~client()
  {
    if (instance_ptr_ != nullptr)
      td_json_client_destroy(instance_ptr_);
  };

  void client::send( const std::string & request )
  {
    td_json_client_send(instance_ptr_, request.c_str());
  };

  json client::execute( const std::string & request )
  {
    return json(nlohmann::json(td_json_client_execute(instance_ptr_, request.c_str())));
  };

  json client::receive( double timeout )
  {
    const char *ans = td_json_client_receive(instance_ptr_, timeout);

    if (ans)
    {
      if (json(nlohmann::json::parse(ans)).find("@type") == "error" && json(nlohmann::json::parse(ans)).find("code") == 429)
      {
        std::this_thread::sleep_for(std::chrono::nanoseconds(32000000));
        return receive(timeout);
      }
      return json(nlohmann::json::parse(ans));
    }
    return json(nlohmann::json());
  };
}