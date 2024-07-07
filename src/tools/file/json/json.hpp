#ifndef _json_hpp__
#define _json_hpp__

#include <string>

#include <nlohmann/json.hpp>

#include "../file.hpp"

namespace tg_cpp_app
{
  class json
  {
  private:
    nlohmann::json content_;

  private:
    json( nlohmann::json & new_content );

  public:
    json( const file & new_file );
    json( const json & new_json );
    json( json && new_json );
    json & operator=( const json & new_json );
    json & operator=( json && new_json );
    json( const std::string & new_str_json );
    ~json();

  public:
    nlohmann::json & find( const std::string & key );
    std::string to_string() const;
    nlohmann::json & operator[]( const std::string & key );
  };
};
#endif // _json_hpp__