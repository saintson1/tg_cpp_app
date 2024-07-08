#ifndef _file_hpp__
#define _file_hpp__

#include "file.hpp"

#include <string>
#include <vector>
#include <variant>
#include <exception>
#include <fstream>

#include <boost/filesystem.hpp>

namespace tg_cpp_app
{
  class file
  {
  private:
    class content_node
    {
    public:
      using content_node_variant_type = std::variant<std::string, content_node *>;
    private:
      std::string name_;
      std::vector<content_node_variant_type> contents_;

    public:
      content_node( std::string new_name_, const content_node_variant_type & new_content = nullptr );
      content_node( std::string new_name_, const std::vector<content_node *> & new_contents );
      content_node( const content_node & new_node );
      content_node( content_node && new_node );
      ~content_node();

    private:
      content_node * find( const std::string & find_name );

    public:
      const std::vector<content_node_variant_type> & get_content();
      std::vector<std::string> get_string_content();
      const std::vector<content_node_variant_type> operator[]( const std::string & key );
      content_node_variant_type operator[]( int key );
      const std::vector<std::string> find_content( const std::string & find_name );
      const std::string & get_name();
    };
  private:
    boost::filesystem::path path_;
    content_node *content_;

    content_node * req_search( const boost::filesystem::path &entity );

  public:
    file();
    file(const std::string & path_name);
    file(const file & new_file);
    file & operator=(const file & new_file);
    file(file && new_file);
    file & operator=(file && new_file);
    ~file();

  public:
    std::string get_content() const;
    std::vector<content_node *> get_subfiles() const;
    std::string get_filename() const;
  };
};
#endif // _file_hpp__