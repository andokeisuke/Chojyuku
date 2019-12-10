# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "chjk: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ichjk:/home/ando/Chojyuku/src/chjk/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(chjk_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" NAME_WE)
add_custom_target(_chjk_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "chjk" "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" ""
)

get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" NAME_WE)
add_custom_target(_chjk_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "chjk" "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(chjk
  "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chjk
)
_generate_msg_cpp(chjk
  "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chjk
)

### Generating Services

### Generating Module File
_generate_module_cpp(chjk
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chjk
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(chjk_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(chjk_generate_messages chjk_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_cpp _chjk_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_cpp _chjk_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chjk_gencpp)
add_dependencies(chjk_gencpp chjk_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chjk_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(chjk
  "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chjk
)
_generate_msg_eus(chjk
  "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chjk
)

### Generating Services

### Generating Module File
_generate_module_eus(chjk
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chjk
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(chjk_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(chjk_generate_messages chjk_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_eus _chjk_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_eus _chjk_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chjk_geneus)
add_dependencies(chjk_geneus chjk_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chjk_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(chjk
  "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chjk
)
_generate_msg_lisp(chjk
  "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chjk
)

### Generating Services

### Generating Module File
_generate_module_lisp(chjk
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chjk
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(chjk_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(chjk_generate_messages chjk_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_lisp _chjk_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_lisp _chjk_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chjk_genlisp)
add_dependencies(chjk_genlisp chjk_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chjk_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(chjk
  "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chjk
)
_generate_msg_nodejs(chjk
  "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chjk
)

### Generating Services

### Generating Module File
_generate_module_nodejs(chjk
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chjk
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(chjk_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(chjk_generate_messages chjk_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_nodejs _chjk_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_nodejs _chjk_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chjk_gennodejs)
add_dependencies(chjk_gennodejs chjk_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chjk_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(chjk
  "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chjk
)
_generate_msg_py(chjk
  "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chjk
)

### Generating Services

### Generating Module File
_generate_module_py(chjk
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chjk
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(chjk_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(chjk_generate_messages chjk_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/unit_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_py _chjk_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ando/Chojyuku/src/chjk/msg/vw_cmd.msg" NAME_WE)
add_dependencies(chjk_generate_messages_py _chjk_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chjk_genpy)
add_dependencies(chjk_genpy chjk_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chjk_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chjk)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chjk
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(chjk_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chjk)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chjk
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(chjk_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chjk)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chjk
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(chjk_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chjk)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chjk
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(chjk_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chjk)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chjk\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chjk
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(chjk_generate_messages_py std_msgs_generate_messages_py)
endif()
