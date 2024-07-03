to build proj:

# to build tdlib:
- install tdlib proj : (zip_installer)[https://tdlib.github.io/td/build.html]
- build td lib by officale guide
- to link tdlibs lib for you proj, add this cmake command in build dir: `cmake -DCMAKE_BUILD_TYPE=Release -DTd_DIR=<PATH_TO_TDLIB_BUILD>>\lib\cmake\Td\ ..`

# to build boost:
- install boost by officale web-site
- build boost by officale guide(from bootstrap.bat)
- to link boost libs:
    ```
    set(BOOST_ROOT "<PATH_TO_BOOST_BUILD_DIR>")
    set(BOOST_INCLUDEDIR "PATH_TO_BOOST_BUILD_DIR/include/boost-1_85")
    find_package(Boost COMPONENTS filesystem)
    ```
- copy header files dir to ./external/includes/boost

# to execute program:
  - build prog with cmake
    1. create build dir
    2. build prog from CMakeList.txt
    3. copy tdlib.dll files from tdlib build dir