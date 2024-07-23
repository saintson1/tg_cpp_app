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

  public:
    json( const nlohmann::json & new_content );
    json( nlohmann::json && new_content );
    json( const file & new_file );
    json( const json & new_json );
    json( json && new_json );
    // json( const std::string & new_str_json );
    json & operator=( const json & new_json );
    json & operator=( json && new_json );
    json & operator=( const nlohmann::json & new_content );
    json & operator=( const std::string & new_str_json );
    ~json();

  public:
    nlohmann::json & find( const std::string & key );
    std::string to_string() const;
    nlohmann::json & operator[]( const std::string & key );

    nlohmann::json::iterator begin();
    nlohmann::json::iterator end();

    bool is_empty();

  };
};
#endif // _json_hpp__