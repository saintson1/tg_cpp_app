#include <stdexcept>

#include "client.hpp"

namespace tg_cpp_app {
  client::client()
  {
    instance_ptr_ = td_json_client_create();

    const char *res = td_json_client_receive(instance_ptr_, 1);

    if (instance_ptr_ == nullptr)
      throw std::runtime_error("tg client cann't be created");
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

  nlohmann::json client::send( std::string request )
  {
    td_json_client_send(instance_ptr_, request.c_str());
    const char *res = td_json_client_receive(instance_ptr_, 1);

    return nlohmann::json::parse(res);
  };
}